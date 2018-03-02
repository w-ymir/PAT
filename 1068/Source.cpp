#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

using Size24 = int;
using Arr = vector<vector<Size24>>;
using ArrRow = vector<Size24>;

// Check vec[row][col] with its neighbours using threshold.
bool exceedsThreshold(const Arr& vec, Size24 threshold, int row, int col)
{
	vector<pair<int, int>> neighbours(
		{
			{row - 1, col - 1}, {row, col - 1}, {row + 1, col - 1},
			{row - 1, col},						{row + 1, col},
			{row - 1, col + 1}, {row, col + 1}, {row + 1, col + 1}
		});
	bool result = true;
	for (auto pos : neighbours)
	{
		if (pos.first < 0 || pos.first >= (int)vec.size()
			|| pos.second < 0 || pos.second >= (int)vec[row].size())
			continue;
		if (abs(vec[row][col] - vec[pos.first][pos.second]) <= threshold)
		{
			result = false;
			break;
		}
	}
	return result;
}

int main()
{
	// Get basic data.
	int width, height;
	Size24 threshold;
	cin >> width >> height >> threshold;
	// Get image.
	Arr image(height, ArrRow(width, 0));
	image.reserve(height);
	map<Size24, int> pixelCounts;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> image[i][j];
			pixelCounts[image[i][j]]++;
		}
	}

	// Process.
	int posX = 0, posY = 0, unique = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (pixelCounts[image[i][j]] == 1 && exceedsThreshold(image, threshold, i, j))
			{
				unique++;
				posX = i;
				posY = j;
			}
		}
	}

	// Test.
	switch (unique)
	{
	case 0:
		cout << "Not Exist" << endl;
		break;
	case 1:
		cout << "(" << posY + 1 << ", " << posX + 1 << "): " << image[posX][posY] << endl;
		break;
	default:
		cout << "Not Unique" << endl;
		break;
	}

	return 0;
}