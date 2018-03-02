#include <iostream>
#include <string>
#include <set>
#include <locale>	// toupper

using namespace std;

void strToUpper(string &str)
{
	for (string::iterator it = str.begin(); it != str.end(); ++it)
		*it = toupper(*it);
}

int main()
{
	// Get data
	string s1, s2;
	cin >> s1 >> s2;

	// Process
	set<char> checked;
	string missed("");
	strToUpper(s1);
	strToUpper(s2);
	for (size_t i = 0; i < s1.size(); ++i)
	{
		char ch = s1[i];
		if (checked.find(ch) != checked.end())	// this char has been checked
			continue;
		if (s2.find(ch) == string::npos)	// this char never appears in s2
			missed.push_back(ch);
		checked.insert(ch);
	}

	// Output
	cout << missed << endl;

	return 0;
}