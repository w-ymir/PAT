#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Get team id from string
int getTeam(string &str)
{
	string tmp = str.substr(0, str.find('-'));
	return atoi(tmp.c_str());
}

int main()
{
	// Get number of items.
	int num;
	cin >> num;

	// Get data.
	vector<int> vi(1000, 0);
	for (int i = 0; i < num; ++i)
	{
		string str;
		int score;
		cin >> str >> score;
		vi[getTeam(str) - 1] += score;
	}

	// Find.
	pair<int, int> top(make_pair(-1, 0));	// (team, score)
	for (int i = 0; i < 1000; ++i)
	{
		if (vi[i] > top.second)
			top = make_pair(i, vi[i]);
	}

	// Output
	cout << top.first + 1 << " " << top.second << endl;

	return 0;
}