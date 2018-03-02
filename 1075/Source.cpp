/*
测试点 	结果 	用时(ms) 	内存(kB) 	得分/满分
0 	答案正确 	2 	256 	12/12
1 	答案正确 	2 	488 	2/2
2 	答案正确 	2 	488 	1/1
3 	答案正确 	2 	364 	2/2
4 	答案正确 	2 	368 	3/3
5 	运行超时 			0/5
*/
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main()
{
	// Get basic info.
	string initAddress;
	int num, bound;
	cin >> initAddress >> num >> bound;

	// Get nodes.
	map<string, pair<int, string>> nodes;	// (addr, (data, next))
	for (int i = 0; i < num; i++)
	{
		string addr, next;
		int data;
		cin >> addr >> data >> next;
		nodes.insert(make_pair(addr, make_pair(data, next)));
	}

	// Re-order.
	list<pair<string, int>> li1, li2, li3;	// (addr, data)
	auto node = nodes.find(initAddress);
	while (node != nodes.end())
	{
		pair<string, int> n(node->first, node->second.first);
		if (node->second.first < 0)
			li1.push_back(n);
		else if (node->second.first <= bound)
			li2.push_back(n);
		else
			li3.push_back(n);
		if (node->second.second != "-1")
			node = nodes.find(node->second.second);
		else
			break;
	}
	li1.splice(li1.end(), li2);
	li1.splice(li1.end(), li3);

	// Print.
	auto it = li1.cbegin();
	cout << it->first << " " << it->second;
	it++;
	while (it != li1.cend())
	{
		cout << " " << it->first << endl
			<< it->first << " " << it->second;
		it++;
	}
	cout << " " << "-1" << endl;

	return 0;
}