#include <iostream>
#include <string>

using namespace std;

const string leftBound = "1814/09/05";	// excluded
const string rightBound = "2014/09/07";	// excluded

int main()
{
	// Get number of persons.
	int num;
	cin >> num;

	// Read data.
	int nValid = 0;
	string earliest = rightBound, latest = leftBound;	// the dates
	string oldest, youngest;	// the names
	for (int i = 0; i < num; i++)
	{
		string curName, curDate;
		cin >> curName >> curDate;
		if (curDate > leftBound && curDate < rightBound)
		{
			nValid++;
			if (curDate < earliest)
			{
				earliest = curDate;
				oldest = curName;
			}
			if (curDate > latest)
			{
				latest = curDate;
				youngest = curName;
			}
		}
	}

	// Print.
	if (nValid == 0)
		cout << nValid << endl;
	else
		cout << nValid << " " << oldest << " " << youngest << endl;

	return 0;
}