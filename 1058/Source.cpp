#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Answer
{
	int fullScore, totalItems, numOfCorrectItems;
	string choices;
	Answer() : fullScore(0), totalItems(0), numOfCorrectItems(0), choices("") {}
};

void readAnswers(string &str, vector<string> &stu)
{
	int p1 = str.find('(');
	int p2 = str.find(' ', p1 + 1);
	while (p1 != string::npos && p2 != string::npos)
	{
		string currStr("");	// answer of one question
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
	vector<vector<string>> stuAnswers;
	stuAnswers.reserve(nStudents);
	for (int i = 0; i < nStudents; ++i)
	{
		string raw;
		getline(cin, raw);
		vector<string> currStuAnswers;
		readAnswers(raw, currStuAnswers);
		stuAnswers.push_back(currStuAnswers);
	}

	// Analyse.
	vector<int> stuScores(nStudents, 0);	// scores of each student
	vector<int> qFaults(nQuestions, 0);	// number of faults of each question
	for (int i = 0; i < nStudents; ++i)
	{
		for (int j = 0; j < nQuestions; ++j)
		{
			if (stuAnswers[i][j] == cAnswers[j].choices)
				stuScores[i] += cAnswers[j].fullScore;
			else
				++qFaults[j];
		}
	}
	// The question with the most faults.
	int faults = 0;
	vector<int> qSerial;
	for (int i = 0; i < nQuestions; ++i)
	{
		if (qFaults[i] != 0 && qFaults[i] > faults)
		{
			faults = qFaults[i];
			qSerial.clear();
			qSerial.push_back(i);
		}
		else if (qFaults[i] == faults)
		{
			qSerial.push_back(i);
		}
	}

	// Output.
	// Scores of each student
	for (int i = 0; i < nStudents; ++i)
		cout << stuScores[i] << endl;
	// On most faults
	if (faults == 0)
		cout << "Too simple" << endl;
	else
	{
		cout << faults;
		for (size_t i = 0; i < qSerial.size(); ++i)
			cout << " " << qSerial[i] + 1;
		cout << endl;
	}

	return 0;
}