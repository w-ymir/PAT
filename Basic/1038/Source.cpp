#include <iostream>
#include <vector>

using namespace std;

const int FULLSCORE = 100;

int main()
{
	// Get number of students.
	int num;
	cin >> num;
	// Get scores, but only add 1 at corresponding position.
	vector<int> stu(FULLSCORE + 1, 0);
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		++stu[tmp];
	}

	// Get number of search scores.
	int searchNum;
	cin >> searchNum;
	vector<int> scores;
	scores.reserve(searchNum);
	for (int i = 0; i < searchNum; ++i)
	{
		int tmp;
		cin >> tmp;
		scores.push_back(tmp);
	}

	// Output
	if (searchNum != 0)
	{
		cout << stu[scores[0]];
		for (int i = 1; i < searchNum; ++i)
			cout << " " << stu[scores[i]];
	}
	cout << endl;

	return 0;
}