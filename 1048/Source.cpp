#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string MOD("0123456789JQK");

int main()
{
	// Get data.
	string raw1, raw2;
	cin >> raw1 >> raw2;
	string key(raw1.rbegin(), raw1.rend());
	string str(raw2.rbegin(), raw2.rend());
	if (key.size() > str.size())	// !!!
		str.append(key.size() - str.size(), '0');

	// Encrypt.
	string cipher(str);
	int i, pos;	// str[i], key[pos]
	for (i = 0, pos = 0; i < (int)cipher.size() && pos < (int)key.size(); ++i, ++pos)
	{
		if (i % 2 == 0)
		{
			cipher[i] = MOD[((key[pos] - '0') + (str[i] - '0')) % 13];
		}
		else
		{
			int tmp = (str[i] - '0') - (key[pos] - '0');
			if (tmp < 0)
				tmp += 10;
			cipher[i] = '0' + tmp;
		}
	}

	// Output
	for (string::reverse_iterator it = cipher.rbegin(); it != cipher.rend(); ++it)
		cout << *it;
	cout << endl;

	return 0;
}