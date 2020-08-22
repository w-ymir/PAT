/*
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	1 	368 	13/13
1 	����ȷ 	2 	368 	2/2
2 	����ȷ 	1 	240 	2/2
3 	���г�ʱ 			0/4
4 	���г�ʱ 			0/4
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string>::const_iterator getCouple(const vector<string>& vec, vector<string>::const_iterator it)
{
	return distance(vec.cbegin(), it) % 2 == 0 ? it + 1 : it - 1;
}

int main()
{
	// Get info of couples.
	int nCouples;
	cin >> nCouples;
	vector<string> couples;
	couples.reserve(nCouples * 2);
	for (int i = 0; i < nCouples * 2; i++)
	{
		string curId;
		cin >> curId;
		couples.push_back(curId);
	}
	// Get info of the party.
	int nParticipants;
	cin >> nParticipants;
	set<string> participants;
	for (int i = 0; i < nParticipants; i++)
	{
		string curId;
		cin >> curId;
		participants.insert(curId);
	}

	// Check each participant.
	vector<string> singles;
	auto it = participants.begin();
	while (it != participants.end())
	{
		auto itCouple = find(couples.cbegin(), couples.cend(), *it);
		if (itCouple != couples.cend())
		{
			auto itParticipant = participants.find(*getCouple(couples, itCouple));
			if (itParticipant != participants.end())
			{
				it++;
				continue;
			}
			else
			{
				singles.push_back(*it);
			}
		}
		else
		{
			singles.push_back(*it);
		}
		it++;
	}

	// Print.
	cout << singles.size() << endl;
	if (singles.size() != 0)
	{
		auto it = singles.cbegin();
		cout << *it++;
		while (it != singles.cend())
			cout << " " << *it++;
		cout << endl;
	}

	return 0;
}