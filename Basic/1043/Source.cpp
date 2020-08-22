#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

const string pat("PATest");

// Take the first ch from lst
bool take(char ch, list<char> &lst)
{
	list<char>::iterator it = find(lst.begin(), lst.end(), ch);
	if (it == lst.end())	// not found
		return false;
	else
		lst.erase(it);
	return true;
}

int main()
{
	// Get string.
	string raw;
	getline(cin, raw);

	// Only store usable chars.
	list<char> lc;
	for (size_t i = 0; i < raw.size(); ++i)
		if (pat.find(raw[i]) != string::npos)
			lc.push_back(raw[i]);

	// Ordered output
	string str("");
	int pos = 0;	// position in pat
	while (lc.size() != 0)
	{
		if (take(pat[pos], lc))
		{
			str.push_back(pat[pos]);
		}
		++pos;
		if (pos == pat.size())
			pos = 0;
	}

	// Output
	cout << str << endl;

	return 0;
}