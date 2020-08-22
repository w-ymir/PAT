#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	// Get number of items.
	int num;
	cin >> num;

	// Get data.
	vector<double> data;
	data.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		double tmp;
		cin >> tmp;
		data.push_back(tmp);
	}

	// Calculate.
	double sum = 0.0;
	for (size_t i = 0; i < data.size(); ++i)
	{
		sum += data[i] * ((num - i) * (i + 1));
	}

	// Output.
	cout << fixed << setprecision(2) << sum << endl;

	return 0;
}