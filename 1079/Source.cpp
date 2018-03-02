#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int StepMax = 10;

bool isPalindrome(const string& str)
{
	return equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}

string reverseString(const string& str)
{
	return string(str.crbegin(), str.crend());
}

string palimPlus(const string& str)
{
	string sumRev;	// the sum reversed
	sumRev.reserve(str.size() + 1);
	auto it1 = str.crbegin();
	auto it2 = str.cbegin();
	int carry = 0;
	while (it1 != str.crend())
	{
		int digitSum = carry + (*it1 - '0') + (*it2 - '0');
		carry = digitSum / 10;
		sumRev.push_back(digitSum % 10 + '0');
		it1++;
		it2++;
	}
	if (carry != 0)
		sumRev.push_back(carry + '0');
	return reverseString(sumRev);
}

int main()
{
	// Get string of integer.
	string num;
	cin >> num;

	// Check.
	int step = 0;
	bool found = false;
	while (step < StepMax)
	{
		if (isPalindrome(num))
		{
			found = true;
			break;
		}
		else
		{
			string newNum = palimPlus(num);
			cout << num << " + " << reverseString(num) << " = " << newNum << endl;
			num = newNum;
		}
		step++;
	}

	// Print result.
	if (found)
		cout << num << " is a palindromic number." << endl;
	else
		cout << "Not found in " << StepMax << " iterations." << endl;

	return 0;
}