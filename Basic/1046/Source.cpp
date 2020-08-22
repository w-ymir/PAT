#include <iostream>

using namespace std;

typedef int Result;
const Result AWins = 1;
const Result BWins = -1;
const Result Draw = 0;

// Get result of a round
// sn - what n says
// hn - what n shows with hand
Result getResult(int s1, int h1, int s2, int h2)
{
	int sum = s1 + s2;
	if (h1 == sum && h2 == sum || h1 != sum && h2 != sum)
		return Draw;
	else if (h1 == sum)
		return AWins;
	else
		return BWins;
}

void orderWine(Result res, int &wineA, int &wineB)
{
	switch (res)
	{
	case AWins:
		++wineB;
		break;
	case BWins:
		++wineA;
		break;
	case Draw:
		break;
	default:
		break;
	}
}

int main()
{
	// Get number of rounds
	int num;
	cin >> num;

	// Process.
	int wineA = 0, wineB = 0;
	for (int i = 0; i < num; ++i)
	{
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		orderWine(getResult(t1, t2, t3, t4), wineA, wineB);
	}

	// Output.
	cout << wineA << " " << wineB << endl;

	return 0;
}