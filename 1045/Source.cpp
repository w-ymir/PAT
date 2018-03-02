/*
���Ե� 	��� 	��ʱ(ms) 	�ڴ�(kB) 	�÷�/����
0 	����ȷ 	5 	376 	12/12
1 	����ȷ 	60 	4076 	2/2
2 	����ȷ 	47 	640 	4/4
3 	����ȷ 	60 	1520 	3/3
4 	����ȷ 	66 	1152 	2/2
5 	�𰸴��� 	78 	1136 	0/2
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	// Get number of ints.
	int num;
	cin >> num;
	// Get ints.
	vector<int> orig;
	orig.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		orig.push_back(tmp);
	}

	// Process.
	vector<int> pool(orig);
	sort(pool.begin(), pool.end());

	int p;
	for (p = 0; p < num; ++p)
	{
		if (orig[p] != pool[p])
			break;
	}
	int pos1 = p;

	for (p = num - 1; p > pos1; --p)
	{
		if (orig[p] != pool[p])
			break;
	}
	int pos2 = p + 1;

	// Prepare output.
	list<int> res;
	for (int i = 0; i < pos1; ++i)
		res.push_back(pool[i]);
	for (int i = pos2; i < num; ++i)
		res.push_back(pool[i]);

	// Output.
	cout << res.size() << endl;

	if (res.size() != 0)
	{
		list<int>::iterator it = res.begin();
		cout << *it;
		++it;
		while (it != res.end())
		{
			cout << " " << *it;
			++it;
		}
	}
	cout << endl;

	return 0;
}