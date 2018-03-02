#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	// Get basic info.
	string initAddr;
	int nNodes, nReverse;
	cin >> initAddr >> nNodes >> nReverse;

	// Read nodes.
	map<string, pair<int, string>> nodes;	// (addr, (data, next))
	for (int i = 0; i < nNodes; i++)
	{
		string addr, next;
		int data;
		cin >> addr >> data >> next;
		nodes[addr] = make_pair(data, next);
	}

	// Store in order.
	vector<pair<string, int>> li;	// (addr, data)
	li.reserve(nodes.size());
	auto itNodes = nodes.find(initAddr);
	while (itNodes != nodes.end())
	{
		li.push_back(make_pair(itNodes->first, itNodes->second.first));
		itNodes = nodes.find(itNodes->second.second);
	}

	// Reverse.
	size_t pos1 = 0, pos2 = nReverse;
	while (pos2 <= li.size())
	{
		auto it1 = li.begin();
		auto it2 = li.begin();
		advance(it1, pos1);
		advance(it2, pos2);
		reverse(it1, it2);
		pos1 = pos2;
		pos2 += nReverse;
	}

	// Print.
	auto itLi = li.cbegin();
	cout << itLi->first << " " << itLi->second;
	itLi++;
	while (itLi != li.cend())
	{
		cout << " " << itLi->first << endl
			<< itLi->first << " " << itLi->second;
		itLi++;
	}
	cout << " -1" << endl;

	return 0;
}