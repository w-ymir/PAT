#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	// Get input
	string str;
	getline(cin, str);

	// Count.
	vector<int> counts(26, 0);	// counts of the 26 letters
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
			++counts[tolower(str[i]) - 'a'];
	}

	// Find.
	pair<char, int> res('?', 0);
	for (size_t i = 0; i < counts.size(); ++i)
	{
		if (counts[i] > res.second)
			res = make_pair('a' + i, counts[i]);
	}

	// Output
	cout << res.first << " " << res.second << endl;

	return 0;
}