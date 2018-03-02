#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

using PatNum = vector<short>;

// Ignore leading '0's.
string simplifyString(const string& str)
{
	string result;
	size_t pos = str.find_first_not_of('0');
	result = (pos == 0) ? str :
		(pos == string::npos) ? "0" : str.substr(pos);
	return result;
}

PatNum str2vec(const string& rawStr)
{
	string str = simplifyString(rawStr);
	PatNum result;
	result.reserve(str.size());
	for (auto s = str.rbegin(); s != str.rend(); s++)
	{
		result.push_back(*s - '0');
	}
	return result;
}

// Remove unnecessary '0's.
void simplifyPatNum(PatNum& num)
{
	while (num[num.size() - 1] == 0 && num.size() > 1)
		num.pop_back();
}

PatNum patPlus(const PatNum& scale, const PatNum& n1, const PatNum& n2)
{
	PatNum result;
	size_t pos = 0;
	int carry = 0;
	while (pos < max(n1.size(), n2.size()) || carry != 0)
	{
		int d1 = n1.size() > pos ? n1[pos] : 0;
		int d2 = n2.size() > pos ? n2[pos] : 0;
		int dScale = scale.size() > pos ? scale[pos] : 0;
		if (dScale == 0)
			dScale = 10;
		int dSum = carry + d1 + d2;
		carry = dSum / dScale;
		result.push_back(dSum % dScale);
		pos++;
	}
	if (result.size() == 0)
		result.push_back(0);
	else
		simplifyPatNum(result);
	return result;
}

string printPatNum(const PatNum& num)
{
	stringstream ss;
	for (auto it = num.rbegin(); it != num.rend(); it++)
	{
		ss << *it;
	}
	return ss.str();
}

int main()
{
	// Get scale.
	string str;
	cin >> str;
	PatNum scale = str2vec(str);
	
	// Get two numbers.
	cin >> str;
	PatNum num1 = str2vec(str);
	cin >> str;
	PatNum num2 = str2vec(str);

	// Calculate.
	PatNum sum = patPlus(scale, num1, num2);

	// Print.
	cout << printPatNum(sum) << endl;

	return 0;
}