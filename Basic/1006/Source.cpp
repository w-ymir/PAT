#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string strBai(9, 'B');
const string strShi(9, 'S');
const string str1("123456789");

// Expand to n digits.
string expand(int digit, int n)
{
	string res;
	switch (digit)
	{
	case 3:
		res = strBai.substr(0, n);
		break;
	case 2:
		res = strShi.substr(0, n);
		break;
	case 1:
		res = str1.substr(0, n);
		break;
	default:
		res = "?";
		break;
	}
	return res;
}

// Get number of digits in n.
int getDigNum(int n)
{
	int res = 0;
	if (n >= 100)
		res = 3;
	else if (n >= 10)
		res = 2;
	else if (n >= 0)
		res = 1;
	return res;
}

int main()
{
	// Read input number.
	int orig;
	cin >> orig;

	// Get number of digits.
	int n = getDigNum(orig);

	// Expand each digit.
	vector<string> vs;
	for (int i = 1; i <= n; ++i)
	{
		vs.push_back(expand(i, orig % 10));
		orig /= 10;
	}

	// Output
	for (vector<string>::const_reverse_iterator iter = vs.crbegin(); iter != vs.crend(); ++iter)
		cout << *iter;
	cout << endl;

	return 0;
}