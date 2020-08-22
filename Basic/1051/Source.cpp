#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// Get numbers
	double r1, p1, r2, p2;
	cin >> r1 >> p1 >> r2 >> p2;

	// Multiply
	double r = r1 * r2, p = p1 + p2;
	// Transform
	double re = r * cos(p), im = r * sin(p);

	// Output
	cout << (re >= -0.005 ? "" : "-")
		<< fixed << setprecision(2) << fabs(re)
		<< (im >= -0.005 ? "+" : "-")
		<< fixed << setprecision(2) << fabs(im)
		<< "i" << endl;

	return 0;
}