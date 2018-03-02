#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	// Get data.
	string raw;
	cin >> raw;

	// Process.
	istringstream iss(raw);
	char ch;
	map<int, int> stat;
	while (iss.get(ch))
	{
		int num = ch - '0';
		if (stat.find(num) == stat.end())
			stat[num] = 1;
		else
			++stat[num];
	}

	// Print
	for (map<int, int>::const_iterator it = stat.cbegin(); it != stat.cend(); ++it)
		cout << it->first << ":" << it->second << endl;

	return 0;
}