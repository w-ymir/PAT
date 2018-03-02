#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int powerToInt(string pow)
{
	istringstream iss(pow);
	int res;
	iss >> res;
	return res;
}

// Change the base if power < 0.
void pointMoveLeft(string &base, int power)
{
	// Insert zeros.
	string zeros(-power, '0');
	base.insert(1, zeros);
	// Remove old period.
	int pos = base.find('.');
	base.erase(pos, 1);
	// Insert new period.
	base.insert(2, 1, '.');
}
// Change the base if power > 0.
void pointMoveRight(string &base, int power)
{
	// Get number of digits after the period.
	int pos = base.find('.');
	int digits = base.size() - pos - 1;
	if (power > digits)	// Add zeros.
	{
		string zeros(power - digits, '0');
		base.append(zeros);
	}
	else if (power < digits)	// Place the new period.
	{
		base.insert(pos + power + 1, 1, '.');
	}
	// Remove the old period.
	base.erase(pos, 1);
}

void movePoint(string &str, int power)
{
	if (power == 0) return;
	if (power > 0)
		pointMoveRight(str, power);
	else
		pointMoveLeft(str, power);
}

// Remove '+' sign & leading '0's in the beginning if necessary.
void purify(string &str)
{
	// Remove leading '0's.
	int pos = str.find_first_not_of('0', 1);
	if (str[pos] != '.')
		str.erase(1, pos - 1);
	// Remove '+' sign.
	if (str[0] == '+')
		str.erase(0, 1);
}

int main()
{
	// Read.
	string raw;
	cin >> raw;

	// Parse.
	int dividePos = raw.find('E');
	int pointPos = raw.find('.');
	string base = raw.substr(0, dividePos);
	int power = powerToInt(raw.substr(dividePos + 1));

	// Process.
	movePoint(base, power);
	purify(base);

	// Print
	cout << base << endl;

	return 0;
}