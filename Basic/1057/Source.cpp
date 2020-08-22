#include <iostream>
#include <string>

using namespace std;

// Count 0s & 1s in binary form of n
pair<int, int> countBits(int n)
{
	int zeros = 0, ones = 0;
	while (n != 0)
	{
		if (n % 2 == 0)
			++zeros;
		else
			++ones;
		n /= 2;
	}
	return make_pair(zeros, ones);
}

int main()
{
	// Get string.
	string str;
	getline(cin, str);

	// Calculate.
	int sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
		{
			sum += toupper(str[i]) - 'A' + 1;
		}
	}

	// Count bits
	pair<int, int> count = countBits(sum);

	// Output
	cout << count.first << " " << count.second << endl;

	return 0;
}