#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// Get basic info.
	int nStudents, nQuestions;
	cin >> nStudents >> nQuestions;
	// Get questions info.
	vector<int> qScores;
	vector<bool> qAnswers;
	qScores.reserve(nQuestions);
	qAnswers.reserve(nQuestions);
	for (int i = 0; i < nQuestions; ++i)
	{
		int curScore;
		cin >> curScore;
		qScores.push_back(curScore);
	}
	for (int i = 0; i < nQuestions; ++i)
	{
		bool curAnswer;
		cin >> curAnswer;
		qAnswers.push_back(curAnswer);
	}
	// Get answers of students.
	vector<vector<bool>> answers;
	answers.reserve(nStudents);
	for (int i = 0; i < nStudents; ++i)
	{
		vector<bool> curStuAnswers;
		curStuAnswers.reserve(nQuestions);
		for (int j = 0; j < nQuestions; ++j)
		{
			bool curAnswer;
			cin >> curAnswer;
			curStuAnswers.push_back(curAnswer);
		}
		answers.push_back(curStuAnswers);
	}

	// Calculate scores.
	for (int i = 0; i < nStudents; ++i)
	{
		int curStuScore = 0;
		for (int j = 0; j < nQuestions; ++j)
		{
			if (answers.at(i).at(j) == qAnswers.at(j))
				curStuScore += qScores.at(j);
		}
		cout << curStuScore << endl;
	}

	return 0;
}