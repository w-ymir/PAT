#include <iostream>
#include <string>
#include <sstream>

using namespace std;

short str2digit(const string& str)
{
	size_t pos = str.find('T');
	return str.at(pos - 2) - 'A' + 1;
}

int main()
{
	// Get number of digits.
	int num;
	cin >> num;
	cin.ignore();

	// Get each digit.
	stringstream ss;
	for (int i = 0; i < num; i++)
	{
		string curStr;
		getline(cin, curStr);
		ss << str2digit(curStr);
	}

	// Print.
	cout << ss.str() << endl;

	return 0;
}