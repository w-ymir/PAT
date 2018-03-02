#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Convert int in base 10 to string in base b [2..10].
string toBase(int n, int b)
{
	// Digits to vector.
	vector<int> vi;
	do
	{
		vi.push_back(n % b);
		n /= b;
	} while (n != 0);

	// To string.
	string str("");
	for (vector<int>::const_reverse_iterator it = vi.crbegin(); it != vi.crend(); ++it)
		str.push_back('0' + *it);
	return str;
}

int main()
{
	int a, b, base;
	cin >> a >> b >> base;

	cout << toBase(a + b, base) << endl;

	return 0;
}