#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void stringToVector(string &str, vector<char> &vc)
{
	vc.clear();
	for (size_t i = 0; i < str.size(); ++i)
	{
		vc.push_back(str[i] - '0');
	}
}

// divident / divisor = quotient .. retVal
char longDivide(vector<char> &divident, char divisor, vector<char> &quotient)
{
	quotient.clear();
	quotient.reserve(divident.capacity());
	char remainder = 0;
	vector<char>::const_iterator itDivident = divident.cbegin();
	if (divident[0] / divisor == 0)
	{
		remainder = divident[0];
		++itDivident;
	}
	for (; itDivident != divident.cend(); ++itDivident)
	{
		char tmp = remainder * 10 + *itDivident;
		quotient.push_back(tmp / divisor);
		remainder = tmp % divisor;
	}
	if (quotient.size() == 0)
		quotient.push_back((char)0);
	return remainder;
}

string showLongNumber(vector<char> num)
{
	ostringstream oss;
	for (vector<char>::const_iterator it = num.cbegin(); it != num.cend(); ++it)
	{
		char tmp = *it + '0';
		oss << tmp;
	}
	return oss.str();
}

int main()
{
	// Read data.
	string raw;
	char divisor;
	cin >> raw >> divisor;
	divisor -= '0';

	// Prepare for calculation.
	vector<char> divident;
	stringToVector(raw, divident);
	// Calculate.
	vector<char> quotient;
	char remainder;
	remainder = longDivide(divident, divisor, quotient);

	// Output
	remainder += '0';
	cout << showLongNumber(quotient) << " " << remainder << endl;

	return 0;
}