#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const vector<string> digitInPinyin = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

// Calculate the sum of digits in string.
int strDigitSum(string s)
{
	int sum = 0;
	for (size_t i = 0; i < s.size(); ++i)
		sum += s[i] - '0';
	// cout << sum << endl;
	return sum;
}

// Convert num into pinyin.
string numToPinyin(int num)
{
	int digit;
	vector<string> pinyin;

	// Get digits ready.
	do
	{
		digit = num % 10;
		num /= 10;
		pinyin.push_back(digitInPinyin[digit]);
	} while (num != 0);

	// Get output string ready.
	ostringstream outStr;
	int i = pinyin.size() - 1;
	outStr << pinyin[i];
	for (i = pinyin.size() - 2; i >= 0; --i)
	{
		outStr << " " << pinyin[i];
	}

	return outStr.str();
}

int main()
{
	// Read raw input as a string.
	string raw;
	cin >> raw;

	// Calculate digit sum & print as pinyin.
	cout << numToPinyin(strDigitSum(raw)) << endl;

	return 0;
}