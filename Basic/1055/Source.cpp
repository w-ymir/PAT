#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Compare
{
	bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs)
	{
		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;
		else
			return lhs.first < rhs.first;
	}
};

int main()
{
	// Get basic info.
	int num, row;
	cin >> num >> row;

	// Get data.
	vector<pair<string, int>> data;
	data.reserve(num);
	for (int i = 0; i < num; ++i)
	{
		string str;
		int height;
		cin >> str >> height;
		data.push_back(make_pair(str, height));
	}

	// Sort by height.
	sort(data.begin(), data.end(), Compare());

	// Form the matrix.
	int col = num / row;
	int colLast = col + (num % row == 0 ?  0 : num % row);

	// Arrange each row.
	int pos = 0;	// arranging position in data
	for (int i = 0; i < row; ++i)
	{
		int currCol = (i == 0 ? colLast : col);
		vector<string> seq(currCol);	// the sequence of the current row
		int pRight = currCol / 2;
		int pLeft = pRight - 1;
		for (int j = 0; j < currCol; ++j)
		{
			if (j % 2 == 0)
			{
				seq[pRight++] = data[pos++].first;
			}
			else
			{
				seq[pLeft--] = data[pos++].first;
			}
		}
		// Output
		cout << seq[0];
		for (int k = 1; k < (int)seq.size(); ++k)
			cout << " " << seq[k];
		cout << endl;
	}

	return 0;
}