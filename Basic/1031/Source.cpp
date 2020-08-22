#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

const int LENGTH = 18;
const int CODE = 11;
const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char trans[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

// Check if the check code is correct
bool isVerified(const string &id)
{
	int sum = 0;
	for (int i = 0; i < LENGTH - 1; ++i)
		sum += (id[i] - '0') * weight[i];
	if (id[LENGTH - 1] == trans[sum % CODE])
		return true;
	else
		return false;
}

// Check if an ID string is valid
bool isValid(const string &id)
{
	// [0..LENGTH) are all digits
	for (int i = 0; i < LENGTH - 1; ++i)
		if (!isdigit(id[i]))
			return false;
	if (!isVerified(id))
		return false;
	return true;
}

int main()
{
	// Get number of items
	int num;
	cin >> num;

	// Get & check each item
	vector<string> faults;
	string str;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		if (!isValid(str))
			faults.push_back(str);
	}

	// Output
	if (faults.size() == 0)
		cout << "All passed" << endl;
	else
	{
		for (vector<string>::const_iterator it = faults.begin(); it != faults.end(); ++it)
			cout << *it << endl;
	}

	return 0;
}