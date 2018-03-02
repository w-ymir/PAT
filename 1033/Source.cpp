#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Remove all ch in str (upper letter excluded)
void remove(char ch, string &str)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (toupper(str[i]) == ch)
		{
			str.erase(i, 1);
			--i;
		}
	}
}

// Remove upper letters in str
void removeUpper(string &str)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (isupper(str[i]))
		{
			str.erase(i, 1);
			--i;
		}
	}
}

int main()
{
	// Get data
	string badKeys, text;
	getline(cin, badKeys);
	getline(cin, text);

	// For each char in badKeys, remove from text.
	for (int i = 0; badKeys[i] != '\0'; ++i)
	{
		remove(badKeys[i], text);
	}
	// The case of Shift key
	if (badKeys.find('+') != string::npos)
	{
		removeUpper(text);
	}

	// Output
	cout << text << endl;

	return 0;
}