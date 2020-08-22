#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Check if a string is legal (to parse to a number).
bool isLegal(string &str)
{
	const string legal("-.0123456789");
	int posAlpha = str.find_first_not_of(legal);
	if (posAlpha != string::npos)
		return false;

	int posSign = str.find('-');
	if (posSign != string::npos && posSign != 0)
		return false;

	int posPoint = str.find('.');
	if (posPoint != string::npos)
	{
		//if (posPoint == 0 || posSign == 0 && posPoint == 1)
		//	return false;
		if ((int)str.size() - posPoint > 3)
			return false;
		int posPoint2 = str.find('.', posPoint + 1);
		if (posPoint2 != string::npos)
			return false;
	}

	int posLeft = (posSign == string::npos ? 0 : 1);
	int posRight = (posPoint == string::npos ? (int)str.size() : posPoint);
	if (posRight - posLeft > 4)
		return false;
	else if (posRight - posLeft == 4)
	{
		double tmp = atof(str.c_str());
		if (tmp != 1000 && tmp != -1000)
			return false;
	}

	return true;
}

int main()
{
	// Get number of items.
	int num;
	cin >> num;

	// Get items and process.
	int legalNum = 0;
	double sum = 0.0;
	string str;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		if (isLegal(str))
		{
			double curr = atof(str.c_str());
			sum += curr;
			++legalNum;
		}
		else
			cout << "ERROR: " << str << " is not a legal number" << endl;
	}

	// Output
	cout << "The average of " << legalNum << " number" << (legalNum == 1 ? "" : "s") << " is ";
	if (legalNum != 0)
		cout << fixed << setprecision(2) << sum / legalNum;
	else
		cout << "Undefined";
	cout << endl;

	return 0;
}