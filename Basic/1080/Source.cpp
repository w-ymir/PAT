#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Score
{
	int coding = -1;
	int midTerm = -1;
	int endTerm = -1;
	int finalScore = -1;
};

int main()
{
	// Get basic info.
	int nCoding, nMidTerm, nEndTerm;
	cin >> nCoding >> nMidTerm >> nEndTerm;
	
	// Get the scores.
	map<string, Score> scores;
	for (int i = 0; i < nCoding; i++)
	{
		string name;
		int num;
		cin >> name >> num;
		scores[name].coding = num;
	}
	for (int i = 0; i < nMidTerm; i++)
	{
		string name;
		int num;
		cin >> name >> num;
		scores[name].midTerm = num;
	}
	for (int i = 0; i < nEndTerm; i++)
	{
		string name;
		int num;
		cin >> name >> num;
		scores[name].endTerm = num;
	}

	// Calculate final scores.
	vector<pair<string, Score>> certs;
	certs.reserve(scores.size());
	auto it = scores.begin();
	while (it != scores.end())
	{
		if (it->second.coding >= 200)
		{
			it->second.finalScore = (it->second.midTerm > it->second.endTerm) ?
				(int)(0.4 * it->second.midTerm + 0.6 * it->second.endTerm + 0.5) : it->second.endTerm;
			if (it->second.finalScore >= 60)
				certs.push_back(*it);
		}
		it++;
	}

	// Sort
	stable_sort(certs.begin(), certs.end(),
		[](pair<string, Score> a, pair<string, Score> b) {
		return a.second.finalScore > b.second.finalScore;
	});

	// Print.
	for (auto stu : certs)
	{
		cout << stu.first << " "
			<< stu.second.coding << " "
			<< stu.second.midTerm << " "
			<< stu.second.endTerm << " "
			<< stu.second.finalScore << endl;
	}

	return 0;
}