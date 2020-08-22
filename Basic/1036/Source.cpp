#include <iostream>
#include <string>

using namespace std;

int main()
{
	int len;
	char ch;
	cin >> len >> ch;

	int hg = (len + 1) / 2;	// height
	for (int i = 0; i < hg; ++i)
	{
		if (i == 0 || i == hg - 1)
			cout << string(len, ch) << endl;
		else
			cout << ch << string(len - 2, ' ') << ch << endl;
	}

	return 0;
}