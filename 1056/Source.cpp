#include <iostream>
#include <vector>

using namespace std;

int comb(const int &a, const int &b)
{
	return a * 10 + b;
}

int main()
{
	// Get number of ints.
	int num;
	cin >> num;
	// Get ints.
	vector<int> data;
	data.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		data.push_back(tmp);
	}

	// Calculate.
	int sum = 0;
	for (int i = 0; i < (int)data.size(); ++i)
	{
		for (int j = 0; j < (int)data.size(); ++j)
		{
			if (i != j)
			{
				sum += comb(data[i], data[j]);
			}
		}
	}

	// Output
	cout << sum << endl;

	return 0;
}