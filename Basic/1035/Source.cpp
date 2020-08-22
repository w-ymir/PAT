#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	// Get number of items.
	int num;
	cin >> num;
	// Get arrays.
	vector<int> orig, proc;
	orig.reserve(num);
	proc.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		orig.push_back(tmp);
	}
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		proc.push_back(tmp);
	}

	vector<int> test(orig);

	// Check if it is insertion sort.
	bool found = false;	// the given status found
	vector<int>::iterator it = test.begin();
	for (int i = 0; i < num - 1; ++i)
	{
		++it;
		sort(test.begin(), it);
		if (!found)
		{
			if (test == proc)
			{
				found = true;
			}
		}
		else
		{
			cout << "Insertion Sort" << endl;
			// Print
			cout << test[0];
			for (i = 1; i < num; ++i)
				cout << " " << test[i];
			cout << endl;
			break;
		}
	}

	if (!found)
	{
		test = orig;
		// Check if it is merge sort.
		it = test.begin();

		// find number of loops
		int lp = 1;
		while ((int)test.size() > lp)
			lp *= 2;

		for (int i = 0; i < lp; ++i)
		{
			vector<int>::iterator it2;
			int sz = (int)pow(2.0, i);	// current sort size
			int j = 0;
			while (j < num - 1)
			{
				it = test.begin() + j;
				if (j + sz <= num)
					it2 = it + sz;
				else
					it2 = test.end();
				sort(it, it2);
				j += sz;
			}
			if (!found)
			{
				if (test == proc)
				{
					found = true;
				}
			}
			else
			{
				cout << "Merge Sort" << endl;
				// Print
				cout << test[0];
				for (i = 1; i < num; ++i)
					cout << " " << test[i];
				cout << endl;
				break;
			}
		}
	}

	return 0;
}