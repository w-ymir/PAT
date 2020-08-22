#include <iostream>
#include <algorithm>

using namespace std;

const int MAXSIZE = 100;

// Get greatest common divisor.
int gcd(int a, int b)
{
	int res = 0;
	for (int i = 1; i <= min(a, b); ++i)
	{
		if (a % i == 0 && b % i == 0)
			res = i;
	}
	return res;
}

// For arr[size], right shift n positions.
void rightShift(int *arr, int size, int n)
{
	n = n % size;
	if (n == 0) return;

	int loop1 = gcd(size, n);
	int loop2 = size / loop1;
	for (int i = 0; i < loop1; ++i)
	{
		int pos1 = i, pos2 = (i + n) % size;
		int prev, curr = arr[pos1];
		for (int j = 0; j < loop2; ++j)
		{
			prev = curr;
			curr = arr[pos2];
			arr[pos2] = prev;
			// Step to the next position.
			pos1 = pos2;
			pos2 = (pos2 + n) % size;
		}
	}
}

int main()
{
	// Get info.
	int size, shift;
	cin >> size >> shift;
	// Read original data.
	int arr[MAXSIZE];
	for (int i = 0; i < size; ++i)
		cin >> arr[i];

	// Right shift.
	rightShift(arr, size, shift);

	// Output
	cout << arr[0];
	for (int i = 1; i < size; ++i)
		cout << " " << arr[i];
	cout << endl;

	return 0;
}