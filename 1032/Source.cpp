#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct
{
	bool operator()(pair<int, int> &lhs, pair<int, int> &rhs)
	{
		return lhs.second > rhs.second;
	}
} compare;

int main()
{
	// Get number of items
	int num;
	cin >> num;

	// Read items
	map<int, int> pool;
	for (int i = 0; i < num; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (pool.find(a) != pool.end())
		{
			pool[a] += b;
		}
		else
			pool[a] = b;
	}

	// Sort
	vector<pair<int, int>> seq;
	seq.reserve(pool.size());
	for (size_t i = 0; i < pool.size(); ++i)
		seq.push_back(make_pair(i, pool[i]));
	sort(seq.begin(), seq.end(), compare);

	// Output
	if (seq.size() == 0)
		cout << endl;
	else
		cout << seq[0].first << " " << seq[0].second << endl;

	return 0;
}