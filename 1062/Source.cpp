#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int gcd(int larger, int smaller)
{
	if (larger < smaller)
		swap(larger, smaller);
	if (smaller == 0)
		return larger;
	int remainder = larger % smaller;
	return gcd(smaller, remainder);
}

bool parseFraction(const string str, int& numerator, int& denominator)
{
	try
	{
		int pos = str.find('/');
		numerator = atoi(str.substr(0, pos).c_str());
		denominator = atoi(str.substr(pos + 1).c_str());
	}
	catch(...)
	{
		return false;
	}
	return true;
}

int main()
{
	// Get raw input.
	string leftFraction, rightFraction;
	int denominator;
	cin >> leftFraction >> rightFraction >> denominator;

	// Process.
	int leftNumerator, leftDenominator, rightNumerator, rightDenominator;
	if (parseFraction(leftFraction, leftNumerator, leftDenominator)
		&& parseFraction(rightFraction, rightNumerator, rightDenominator))
	{
		// Calculate the bounds.
		if (1.0 * leftNumerator / leftDenominator > 1.0 * rightNumerator / rightDenominator)
		{
			swap(leftNumerator, rightNumerator);
			swap(leftDenominator, rightDenominator);
		}
		int leftBound, rightBound;	// Both bounds are included.
		leftBound = leftNumerator * denominator / leftDenominator + 1;
		rightBound = rightNumerator * denominator / rightDenominator;
		if (rightNumerator * denominator % rightDenominator == 0)
			--rightBound;

		// Prepare numerators.
		vector<int> numerators;
		for (int i = leftBound; i <= rightBound; ++i)
		{
			if (gcd(denominator, i) == 1)
				numerators.push_back(i);
		}

		// Print.
		cout << numerators.at(0) << "/" << denominator;
		for (int i = 1; i < numerators.size(); ++i)
		{
			cout << " " << numerators.at(i) << "/" << denominator;
		}
	}
	else
	{
		cout << "Error occurred when parsing fraction(s)." << endl;
		return 1;
	}

	return 0;
}