#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	// Get data.
	list<char> sell, buy;
	char tmp;
	while ((tmp = cin.get()) != '\n')
		sell.push_back(tmp);
	while ((tmp = cin.get()) != '\n')
		buy.push_back(tmp);

	// Check
	list<char>::iterator it = buy.begin();
	while (it != buy.end())
	{
		list<char>::iterator pos = find(sell.begin(), sell.end(), *it);
		if (pos != sell.end())	// char found
		{
			sell.erase(pos);
			it = buy.erase(it);
		}
		else
			++it;
	}

	// Get result
	if (buy.size() == 0)
		cout << "Yes " << sell.size() << endl;
	else
		cout << "No " << buy.size() << endl;

	return 0;
}