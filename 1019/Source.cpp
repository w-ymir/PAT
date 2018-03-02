#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int vectorToInteger(vector<int> vi)
{
	int result = 0;
	for (vector<int>::const_iterator it = vi.cbegin(); it != vi.cend(); ++it)
		result = result * 10 + *it;
	return result;
}

int reverseVectorToInteger(vector<int> vi)
{
	int result = 0;
	for (vector<int>::const_reverse_iterator it = vi.crbegin(); it != vi.crend(); ++it)
		result = result * 10 + *it;
	return result;
}

void integerToVector(int n, vector<int> &vi)
{
	for (vector<int>::reverse_iterator it = vi.rbegin(); it != vi.rend(); ++it)
	{
		*it = n % 10;
		n /= 10;
	}
}

int main()
{
	// Get raw data.
	int result;
	cin >> result;

	// Process.
	int a, b;
	vector<int> num{ 0, 0, 0, 0 };
	do
	{
		// Prepare data.
		integerToVector(result, num);
		// Sort vector.
		sort(num.begin(), num.end(), greater<int>());
		// Get the three numbers.
		a = vectorToInteger(num);
		b = reverseVectorToInteger(num);
		result = a - b;
		// Print.
		cout << setw(4) << setfill('0') << a << " - "
			<< setw(4) << b << " = "
			<< setw(4) << result << endl;
	} while (result != 6174 && result != 0);

	return 0;
}