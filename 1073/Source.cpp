#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

struct Answer
{
	double fullScore;
	int totalItems, numOfCorrectItems;
	vector<char> choices;
	Answer() : fullScore(0.0), totalItems(0), numOfCorrectItems(0) {}
};

void readAnswers(string &str, vector<vector<char>> &stu)
{
	size_t p1 = str.find('(');
	size_t p2 = str.find(' ', p1 + 1);
	while (p1 != string::npos && p2 != string::npos)
	{
		vector<char> currStr;	// answer of one question
		for (int i = 0; i < atoi(str.substr(p1 + 1, p2 - p1).c_str()); ++i)
		{
			++p2;
			currStr.push_back(str[p2]);
			++p2;
		}
		stu.push_back(currStr);
		p1 = str.find('(', p2 + 1);
		p2 = str.find(' ', p1 + 1);
	}
}

int main()
{
	// Get basic info.
	int nStudents, nQuestions;
	cin >> nStudents >> nQuestions;
	// Get correct answers.
	vector<Answer> cAnswers;
	cAnswers.reserve(nQuestions);
	for (int i = 0; i < nQuestions; ++i)
	{
		Answer currAnswer;
		cin >> currAnswer.fullScore >> currAnswer.totalItems >> currAnswer.numOfCorrectItems;
		for (int j = 0; j < currAnswer.numOfCorrectItems; ++j)
		{
			char ch;
			cin >> ch;
			currAnswer.choices.push_back(ch);
		}
		cAnswers.push_back(currAnswer);
	}
	cin.ignore();

	// Get student answers.
	vector<vector<vector<char>>> stuAnswers;
	stuAnswers.reserve(nStudents);
	for (int i = 0; i < nStudents; ++i)
	{
		string raw;
		getline(cin, raw);
		vector<vector<char>> currStuAnswers;
		readAnswers(raw, currStuAnswers);
		stuAnswers.push_back(currStuAnswers);
	}

	// Analyse.
	vector<double> stuScores(nStudents, 0.0);	// scores of each student
	//vector<int> qFaults(nQuestions, 0);	// number of faults of each question
	map<pair<int, char>, int> wrongChoices;	// ((questionNumber, choice), timesOfFaults)
	for (int i = 0; i < nStudents; ++i)
	{
		for (int j = 0; j < nQuestions; ++j)
		{
			if (stuAnswers[i][j].size() == cAnswers[j].choices.size()
				&& equal(stuAnswers[i][j].begin(), stuAnswers[i][j].end(), cAnswers[j].choices.begin()))
				stuScores[i] += cAnswers[j].fullScore;
			else
			{
				// Give half the score.
				if (includes(cAnswers[j].choices.begin(), cAnswers[j].choices.end(), stuAnswers[i][j].begin(), stuAnswers[i][j].end()))
					stuScores[i] += cAnswers[j].fullScore / 2.0;
				// Record wrong choices.
				vector<char> diff;
				set_symmetric_difference(cAnswers[j].choices.begin(), cAnswers[j].choices.end(), stuAnswers[i][j].begin(), stuAnswers[i][j].end(),
					inserter(diff, diff.begin()));
				for (auto elem : diff)
					wrongChoices[make_pair(j, elem)]++;
			}
		}
	}
	// The question with the most faults.
	int faults = 0;
	vector<pair<int, char>> qSerial;
	for (auto elem : wrongChoices)
	{
		if (elem.second > faults)
		{
			faults = elem.second;
			qSerial.clear();
			qSerial.push_back(elem.first);
		}
		else if (elem.second == faults)
		{
			qSerial.push_back(elem.first);
		}
	}

	// Output.
	// Scores of each student
	for (int i = 0; i < nStudents; ++i)
		cout << fixed << setprecision(1) << stuScores[i] << endl;
	// On most faults
	if (faults == 0)
		cout << "Too simple" << endl;
	else
	{
		for (size_t i = 0; i < qSerial.size(); ++i)
		{
			cout << faults << " " << qSerial[i].first + 1 << "-" << qSerial[i].second << endl;
		}
	}

	return 0;
}