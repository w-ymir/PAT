#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

typedef int Direction;
const Direction Right = 1, Down = 2, Left = 3, Up = 4;
Direction direction = Right;
int htop = 0, hbottom = 0, vleft = 0, vright = 0;	// horizontal top, horizontal bottom (exclude), vertical left, vertial right (exclude) bounds

void changeDirection()
{
	switch (direction)
	{
	case Right: case Down: case Left:
		++direction;
		break;
	case Up:
		direction = Right;
		break;
	default:
		break;
	}
}

void nextStep(int &i, int &j)
{
	switch (direction)
	{
	case Right:
		++j;
		if (j >= vright)
		{
			--j;
			changeDirection();
			++htop;
			++i;
		}
		break;
	case Down:
		++i;
		if (i >= hbottom)
		{
			--i;
			changeDirection();
			--vright;
			--j;
		}
		break;
	case Left:
		--j;
		if (j < vleft)
		{
			++j;
			changeDirection();
			--hbottom;
			--i;
		}
		break;
	case Up:
		--i;
		if (i < htop)
		{
			++i;
			changeDirection();
			++vleft;
			++j;
		}
		break;
	default:
		break;
	}
}

pair<int, int> matParam(int count)
{
	int n = (int)sqrt((float)count);
	while (n > 0 && count % n != 0)
		--n;
	return make_pair(count / n, n);
}

int main()
{
	// Get number of ints.
	int num;
	cin >> num;
	// Read data.
	multiset<int, greater<int>> data;
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin >> tmp;
		data.insert(tmp);
	}

	// Get m & n.
	pair<int, int> param(matParam(num));	// (m, n)

	// Prepare matrix.
	vector<int> innerMat(param.second, 0);
	vector<vector<int>> mat(param.first, innerMat);
	htop = 0, hbottom = param.first, vleft = 0, vright = param.second;
	int i = 0, j = 0;	// to place at position (i, j)
	for (multiset<int, greater<int>>::iterator it = data.begin(); it != data.end(); ++it)
	{
		mat[i][j] = *it;
		nextStep(i, j);
	}

	// Output
	for (i = 0; i < param.first; ++i)
	{
		cout << mat[i][0];
		for (j = 1; j < param.second; ++j)
			cout << " " << mat[i][j];
		cout << endl;
	}

	return 0;
}