#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// Get number of ropes.
	int num;
	cin >> num;
	// Get length of ropes.
	vector<int> ropes;
	ropes.reserve(num);
	for (int i = 0; i < num; i++)
	{
		int curLen;
		cin >> curLen;
		ropes.push_back(curLen);
	}

	// Fold.
	sort(ropes.begin(), ropes.end());
	for (size_t i = 1; i < ropes.size(); i++)
	{
		ropes[i] = (ropes[i - 1] + ropes[i]) / 2;
	}

	// Print.
	cout << ropes[ropes.size() - 1] << endl;

	return 0;
}