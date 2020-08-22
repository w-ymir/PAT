#include <iostream>
#include <list>
#include <cmath>
#include <sstream>

using namespace std;

const int CountsInARow = 10;

// Check if an integer is prime.
bool isPrime(int n)
{
	if (n == 2) return true;

	for (int i = 2; i <= (int)sqrt(n); ++i)
		if (n % i == 0)
			return false;
	return true;
}

// Store prime numbers in [p_lo..p_hi].
void storePrimes(list<int> &vi, int lo, int hi)
{
	vi.clear();
	int num = 2;	// the number to be tested
	int count = 0;	// number of primes counted
	while (count < lo)
	{
		if (isPrime(num))
		{
			++count;
		}
		++num;
	}
	vi.push_back(num-1);
	while (count < hi)
	{
		if (isPrime(num))
		{
			vi.push_back(num);
			++count;
		}
		++num;
	}
}

// Show list as a matrix.
string showMatrix(list<int> &vi)
{
	ostringstream oss;
	int i = 0;
	list<int>::const_iterator it = vi.cbegin();
	while (it != vi.cend())
	{
		if (i % CountsInARow == 0)	// first in a row
			oss << *it;
		else if (i % CountsInARow == (CountsInARow - 1))	// last in a row
			oss << " " << *it << endl;
		else
			oss << " " << *it;
		++i;
		++it;
	}
	if (vi.size() % CountsInARow != 0)	// add a new line if necessary
		oss << endl;
	return oss.str();
}

int main()
{
	// Read input.
	int lower, upper;
	cin >> lower >> upper;

	// Store prime numbers.
	list<int> primes;
	storePrimes(primes, lower, upper);

	// Output
	cout << showMatrix(primes);

	return 0;
}