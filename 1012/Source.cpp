#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>	// accumulate
#include <iomanip>	// setprecision
#include <algorithm>	// max_element

using namespace std;

string A1(vector<int> &vi)
{
	vector<int> tmp;
	for (vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
	{
		if (*it % 10 == 0)
			tmp.push_back(*it);
	}

	ostringstream oss;
	if (tmp.size() == 0)
		oss << "N";
	else
		oss << accumulate(tmp.cbegin(), tmp.cend(), 0);
	return oss.str();
}

string A2(vector<int> &vi)
{
	vector<int> tmp;
	for (vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
	{
		if (*it % 5 == 1)
		{
			if (tmp.size() % 2 == 0)
				tmp.push_back(*it);	// even position
			else
				tmp.push_back(-(*it));	// odd position
		}
	}

	ostringstream oss;
	if (tmp.size() == 0)
		oss << "N";
	else
		oss << accumulate(tmp.cbegin(), tmp.cend(), 0);
	return oss.str();
}

string A3(vector<int> &vi)
{
	int num = 0;
	for (vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
		if (*it % 5 == 2)
			++num;

	ostringstream oss;
	if (num == 0)
		oss << "N";
	else
		oss << num;
	return oss.str();
}

string A4(vector<int> &vi)
{
	vector<int> tmp;
	for (vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
	{
		if (*it % 5 == 3)
			tmp.push_back(*it);
	}

	ostringstream oss;
	if (tmp.size() == 0)
		oss << "N";
	else
	{
		float avg = (float)accumulate(tmp.cbegin(), tmp.cend(), 0) / tmp.size();
		oss << fixed << setprecision(1) << avg;
	}
	return oss.str();
}

string A5(vector<int> &vi)
{
	vector<int> tmp;
	for (vector<int>::const_iterator it = vi.begin(); it != vi.end(); ++it)
	{
		if (*it % 5 == 4)
			tmp.push_back(*it);
	}

	ostringstream oss;
	if (tmp.size() == 0)
		oss << "N";
	else
		oss << *max_element(tmp.cbegin(), tmp.cend());
	return oss.str();
}

int main()
{
	// Get input.
	int num;
	cin >> num;
	vector<int> v;
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	// Process & output
	cout << A1(v) << " " << A2(v) << " " << A3(v) << " " << A4(v) << " " << A5(v) << endl;
	
	return 0;
}