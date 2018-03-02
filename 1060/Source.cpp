#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	// Get number of days.
	int days;
	cin >> days;
	// Get data for the days.
	vector<int> miles;
	miles.reserve(days);
	for (int i = 0; i < days; ++i)
	{
		int curMiles;
		cin >> curMiles;
		miles.push_back(curMiles);
	}

	// Process.
	sort(miles.begin(), miles.end(), greater<int>());
	int pos;
	for (pos = 0; pos < days; ++pos)
	{
		if (miles.at(pos) <= pos + 1)
			break;
	}
	cout << pos << endl;

	return 0;
}