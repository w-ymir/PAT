#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	// Get basic info.
	int nReposts, invertal, startPos;
	cin >> nReposts >> invertal >> startPos;
	startPos--;	// start from 0
	// Get IDs.
	vector<string> reposts;
	reposts.reserve(nReposts);
	for (int i = 0; i < nReposts; i++)
	{
		string curId;
		cin >> curId;
		reposts.push_back(curId);
	}

	// Draw the IDs.
	if ((int)reposts.size() <= startPos)
	{
		cout << "Keep going..." << endl;
	}
	else
	{
		int curPos = startPos;
		set<string> selected;
		while (curPos < (int)reposts.size())
		{
			if (selected.find(reposts[curPos]) == selected.end())
			{
				cout << reposts[curPos] << endl;
				selected.insert(reposts[curPos]);
				curPos += invertal;
			}
			else
			{
				curPos++;
			}
		}
	}

	return 0;
}