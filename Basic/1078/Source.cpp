#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void compress(const string& str)
{
	size_t pos1 = 0;
	char ch = str[pos1];
	while (pos1 < str.size())
	{
		size_t pos2 = str.find_first_not_of(ch, pos1 + 1);
		if (pos2 == string::npos)
			pos2 = str.size();
		if (pos2 - pos1 == 1)
			cout << ch;
		else
			cout << pos2 - pos1 << ch;
		pos1 = pos2;
		ch = str[pos1];
	}
}

void decompress(const string& str)
{
	size_t pos = 0;
	while (pos < str.size())
	{
		if (isdigit(str[pos]))
		{
			size_t posEnd = pos + 1;
			while (isdigit(str[posEnd]))
				posEnd++;
			int times = atoi(str.substr(pos, posEnd - pos).c_str());
			for (int i = 0; i < times; i++)
				cout << str[posEnd];
			pos = posEnd + 1;
		}
		else
		{
			cout << str[pos];
			pos++;
		}
	}
}

int main()
{
	// Get process info.
	char method;
	cin >> method;
	cin.ignore();
	// Get string.
	string str;
	getline(cin, str);

	// Process.
	switch (method)
	{
	case 'C':
		compress(str);
		break;
	case 'D':
		decompress(str);
		break;
	default:
		return 1;
		break;
	}
	cout << endl;

	return 0;
}