// Integer multiplication in "PAT" form.
// 1 'P' (lead) & 1 'T' (lag), with at least 1 'A' between them.
// a (>=0) 'A's before 'P', b (>=1) 'A's between, c 'A's after 'T'. a * b == c.
// No other letters.

#include <iostream>
#include <string>

using namespace std;

// Check if the string is in valid formation.
bool isValid(const string &str)
{
	// 1. No letters other than "PAT".
	if (str.find_first_not_of("PAT") != string::npos)
		return false;

	// 2. Only 1 'P', only 1 'T', 'P' occurs before 'T', at least 1 'A' between them.
	size_t posP1 = str.find_first_of('P'), posP2 = str.find_last_of('P'),
		posT1 = str.find_first_of('T'), posT2 = str.find_last_of('T');
	if (posP1 != posP2 || posT1 != posT2)
		return false;
	else if (posP1 >= posT1 - 1)
		return false;

	// Check the multiplication.
	int multiplier1 = posP1, multiplier2 = posT1 - posP1 - 1, product = str.size() - posT1 - 1;
	if (multiplier1 * multiplier2 != product)
		return false;
	return true;
}

string printResult(bool b)
{
	return b ? "YES" : "NO";
}

int main()
{
	// Read number of items.
	int num;
	cin >> num;

	// Check each item.
	for (int i = 1; i <= num; ++i)
	{
		string str;
		cin >> str;
		cout << printResult(isValid(str)) << endl;
	}

	return 0;
}