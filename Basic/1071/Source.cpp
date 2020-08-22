#include <iostream>

using namespace std;

int main()
{
	// Get basic info.
	int chips, num;
	cin >> chips >> num;

	// Play game.
	for (int i = 0; i < num; i++)
	{
		int n1, b, t, n2;
		cin >> n1 >> b >> t >> n2;
		if (t <= chips)
		{
			if (n2 > n1 && b == 1 || n2 < n1 && b == 0)
			{
				chips += t;
				cout << "Win " << t << "!  Total = " << chips << "." << endl;
			}
			else
			{
				chips -= t;
				cout << "Lose " << t << ".  Total = " << chips << "." << endl;
			}
		}
		else
		{
			cout << "Not enough tokens.  Total = " << chips << "." << endl;
		}
		if (chips == 0)
		{
			cout << "Game Over." << endl;
			break;
		}
	}

	return 0;
}