#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	// Get input.
	string s1, s2;
	char c1, c2;
	cin >> s1 >> c1 >> s2 >> c2;

	// Count.
	int n1, n2;
	n1 = count(s1.cbegin(), s1.cend(), c1);
	n2 = count(s2.cbegin(), s2.cend(), c2);

	// Transfer to integer.
	string res1(n1, c1), res2(n2, c2);
	if (res1.size() == 0) res1 = "0";
	if (res2.size() == 0) res2 = "0";
	istringstream iss1(res1), iss2(res2);
	long num1, num2;
	iss1 >> num1;
	iss2 >> num2;

	// Output
	cout << num1 + num2 << endl;

	return 0;
}