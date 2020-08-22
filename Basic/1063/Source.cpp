#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	// Get number of eigenvalues.
	int nEigenvalues;
	cin >> nEigenvalues;

	// Calculate each norm.
	double spectralRadius = 0.0;
	for (int i = 0; i < nEigenvalues; ++i)
	{
		int vReal, vImage;
		cin >> vReal >> vImage;
		double vNorm = sqrt(vReal * vReal + vImage * vImage);
		if (vNorm > spectralRadius)
			spectralRadius = vNorm;
	}

	// Print.
	cout << fixed << setprecision(2) << spectralRadius << endl;

	return 0;
}