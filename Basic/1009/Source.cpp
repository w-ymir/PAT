#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

int main()
{
	// Get raw input.
	string raw;
	getline(cin, raw);
	istringstream is(raw);

	// Store raw input into list.
	list<string> sentence;
	string tmp;
	while (is >> tmp)
	{
		sentence.push_back(tmp);
	}

	// Output
	list<string>::const_reverse_iterator iter = sentence.crbegin();
	cout << *iter++;
	for (; iter != sentence.crend(); ++iter)
		cout << " " << *iter;
	cout << endl;

	return 0;
}