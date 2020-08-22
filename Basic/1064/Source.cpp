#include <iostream>
#include <string>
#include <set>

using namespace std;

int friendId(string str)
{
	int id = 0;
	for (int i = 0; i < str.size(); i++)
	{
		id += str.at(i) - '0';
	}
	return id;
}

int main()
{
	// Get number of integers.
	int num;
	cin >> num;

	// Get each integer and process.
	set<int> ids;
	for (int i = 0; i < num; i++)
	{
		string curNum;
		cin >> curNum;
		ids.insert(friendId(curNum));
	}

	// Print.
	cout << ids.size() << endl;
	auto it = ids.cbegin();
	cout << *it++;
	while (it != ids.cend())
	{
		cout << " " << *it++;
	}
	cout << endl;

	return 0;
}