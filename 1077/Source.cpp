#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	// Get basic info.
	int nTeams, fullScore;
	cin >> nTeams >> fullScore;

	// Get raw scores.
	vector<vector<int>> scores;
	scores.reserve(nTeams);
	for (int i = 0; i < nTeams; i++)
	{
		vector<int> curStuScores;
		curStuScores.reserve(nTeams);
		int curScore;
		cin >> curScore;	// the score from the teacher
		curStuScores.push_back(curScore);
		// Get scores from other teams.
		for (int j = 1; j < nTeams; j++)
		{
			cin >> curScore;
			if (curScore >= 0 && curScore <= fullScore)
				curStuScores.push_back(curScore);
		}
		scores.push_back(curStuScores);
	}

	// Calculate.
	for (int i = 0; i < nTeams; i++)
	{
		int scoreTeacher, scoreTeams;
		scoreTeacher = scores[i][0];
		sort(scores[i].begin() + 1, scores[i].end());
		scoreTeams = accumulate(scores[i].begin() + 2, scores[i].end() - 1, 0) / (scores[i].size() - 3);
		cout << (scoreTeacher + scoreTeams + 1) / 2 << endl;
	}

	return 0;
}