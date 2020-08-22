#include <iostream>
#include <vector>
#include <set>

using namespace std;

void callatz(int n, set<int> &si)
{
	int step = 0;
	while (n > 1)
	{
		n = (n % 2) ? ((3 * n + 1) / 2) : (n / 2);
		++step;
		si.insert(n);
	}
}

int main()
{
	// Get the amount of items.
	int amount;
	cin >> amount;
	// Get all the test numbers.
	vector<int> vi;
	for (int i = 1; i <= amount; ++i)
	{
		int cur;
		cin >> cur;
		vi.push_back(cur);
	}

	// Store all the mid-numbers.
	set<int> pool;
	for (int i : vi)
	{
		callatz(i, pool);
	}

	// Find the "key numbers".
	set<int> sKey;
	for (int i : vi)
	{
		if (pool.find(i) == pool.end())
			sKey.insert(i);
	}

	// Output
	for (set<int>::const_reverse_iterator iter = sKey.crbegin(); iter != sKey.crend(); ++iter)
	{
		if (iter == sKey.crbegin())
			cout << *iter;
		else
			cout << " " << *iter;
	}
	cout << endl;

	return 0;
}