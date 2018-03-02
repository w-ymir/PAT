#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string showResult(int i, bool b)
{
	ostringstream oss;
	oss << "Case #" << i << ": "
		<< (b ? "true" : "false");
	return oss.str();
}

int main()
{
	long a, b, c;
	int n;	// number of cases
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;
		bool res = (a + b > c) ? true : false;
		cout << showResult(i, res) << endl;
	}

	return 0;
}