#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

const int MOD = 1000000007;
const char p = 'P';
const char a = 'A';
const char t = 'T';

int main()
{
	// Get string.
	string str;
	cin >> str;

	// Process.
	int res = 0;
	string::size_type a1 = str.find(a, str.find(p) + 1);
	string::size_type a2 = str.find_last_of(a, str.find_last_of(t) - 1);

	// for each 'A', find left 'P's and right 'T's.
	while (a1 != string::npos && a1 <= a2)
	{
		int np = 0, nt = 0;
		string::size_type p1 = str.find(p);
		if (p1 != string::npos && p1 < a1)
		{
			string::iterator it1 = str.begin(), it2 = str.begin();
			advance(it1, p1);
			advance(it2, a1);
			np = count(it1, it2, p);
		}
		string::size_type t1 = str.find(t, a1 + 1);
		if (t1 != string::npos)
		{
			string::iterator it1 = str.begin(), it2 = str.end();
			advance(it1, t1);
			nt = count(it1, it2, t);
		}
		res = (res + np * nt) % MOD;
		a1 = str.find(a, a1 + 1);
	}

	// Print
	cout << res << endl;

	return 0;
}