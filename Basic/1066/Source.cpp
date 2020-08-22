#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	// Get image size.
	int height, width;
	cin >> height >> width;
	// Get boundaries.
	int lowerBound, upperBound;
	cin >> lowerBound >> upperBound;
	// Get new color.
	int newColor;
	cin >> newColor;
	// Get image data.
	vector<int> image;
	image.reserve(height * width);
	for (int i = 0; i < height * width; i++)
	{
		int curPoint;
		cin >> curPoint;
		image.push_back(curPoint);
	}

	// Process.
	for (int i = 0; i < image.size(); i++)
	{
		if (image.at(i) >= lowerBound && image.at(i) <= upperBound)
			image.at(i) = newColor;
	}

	// Print.
	for (int i = 0; i < height; i++)
	{
		cout << setw(3) << setfill('0') << right << image.at(i * width);
		for (int j = 1; j < width; j++)
			cout << " " << setw(3) << setfill('0') << right << image.at(i * width + j);
		cout << endl;
	}

	return 0;
}