#include <iostream>

using namespace std;

int callatz(int n)
{
	int step = 0;
	while (n > 1)
	{
		n = (n % 2) ? ((3 * n + 1) / 2) : n / 2;
		++step;
		// cout << step << ": " << n << endl;
	}
	return step;
}

int main()
{
	int n;
	cin >> n;
	cout << callatz(n) << endl;

	return 0;
}