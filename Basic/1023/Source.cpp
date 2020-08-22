#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	// Get data.
	map<char, int> digits;
	for (int i = 0; i < 10; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp != 0)
			digits['0' + i] = tmp;
	}

	// Print
	string res("");
	if (digits.size() == 0)
		res = "0";
	else
	{
		map<char, int>::iterator it = digits.begin();
		if (digits.find('0') != digits.end())	// having 1+ '0'(s)
		{
			++it;
			res.push_back(it->first);
			--it->second;
		}
		it = digits.begin();
		while (it != digits.end())
		{
			string str(it->second, it->first);
			res.append(str);
			++it;
		}
	}

	cout << res << endl;

	return 0;
}