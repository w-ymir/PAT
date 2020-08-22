#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Get prime numbers in (2..bound].
void getPrimes(vector<int> &vi, int bound)
{
	vi.clear();
	vi.push_back(2);
	for (int n = 3; n <= bound; n += 2)	// check if n is prime
	{
		bool isPrime = true;
		for (int i = 3; i <= (int)sqrt(n); i += 2)
		{
			if (n % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			vi.push_back(n);
	}
}

int main()
{
	// Read upper bound.
	int bound;
	cin >> bound;

	// Get prime numbers.
	vector<int> primes;
	getPrimes(primes, bound);
	//for (auto p : primes)
	//	cout << " " << p;
	//cout << endl;

	// Cound twin primes.
	int count = 0;
	for (vector<int>::const_iterator iter = primes.cbegin(); iter != primes.cend() - 1; ++iter)
	{
		if (*(iter+1) - *iter == 2)
		{
			//cout << "> " << *iter << " " << *(iter+1) << endl;
			++count;
		}
	}

	// Output
	cout << count << endl;
	
	return 0;
}