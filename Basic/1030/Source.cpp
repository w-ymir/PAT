#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	// Get basic info.
	int num, p;
	cin >> num >> p;
	// Read the numbers.
	vector<int> arr;
	arr.reserve(num);
	for (int i = 0; i < num; i++)
	{
		int curNum;
		cin >> curNum;
		arr.push_back(curNum);
	}

	// Sort.
	sort(arr.begin(), arr.end());

	// Find the position.
	size_t length = 0;
	size_t pos = 0;
	while (pos < arr.size() && length <= arr.size() - pos)
	{
		long long bound = arr[pos] * (long long)p;
		// Find the upper bound.
		size_t posEnd = pos + length;
		while (posEnd < arr.size())
		{
			if (arr[posEnd] > bound)
				break;
			posEnd++;
		}
		// Calculate the distance.
		size_t dist = posEnd - pos;
		if (dist > length)
			length = dist;
		pos++;
	}

	// Print.
	cout << length << endl;

	return 0;
}