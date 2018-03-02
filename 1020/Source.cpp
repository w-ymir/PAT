#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

struct Data
{
	float amount;
	float totalPrice;
};

struct
{
	bool operator()(const Data &lhs, const Data &rhs)
	{
		return lhs.totalPrice / lhs.amount > rhs.totalPrice / rhs.amount;
	}

} compareData;

int main()
{
	// Get data.
	int types, demand;
	cin >> types >> demand;
	vector<Data> data;
	data.reserve(types);
	for (int i = 0; i < types; ++i)
	{
		Data curr;
		cin >> curr.amount;
		data.push_back(curr);
	}
	for (int i = 0; i < types; ++i)
	{
		cin >> data[i].totalPrice;
	}

	// Sort data.
	sort(data.begin(), data.end(), compareData);

	// Process.
	float price = 0.0f;
	vector<Data>::const_iterator it = data.cbegin();
	while (demand > 0 && it != data.cend())
	{
		float amt = it->amount;
		if (demand >= amt)
		{
			price += it->totalPrice;
			demand -= amt;
		}
		else
		{
			price += it->totalPrice / it->amount * demand;
			demand = 0;
		}
		++it;
	}

	// Print result.
	cout << fixed << setprecision(2) << price << endl;

	return 0;
}