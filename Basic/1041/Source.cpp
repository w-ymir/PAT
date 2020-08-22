#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<string, int> P;
typedef vector<pair<string, int>> VP;

int main()
{
	// Get number of items.
	int num;
	cin >> num;
	// Get data.
	VP pool(num + 1);
	for (int i = 0; i < num; ++i)
	{
		string str;
		int n1, n2;
		cin >> str >> n1 >> n2;
		pool[n1] = make_pair(str, n2);
	}

	// Get number of queries.
	int qnum;
	cin >> qnum;
	// Get queries of seats.
	vector<int> queries(qnum);
	for (int i = 0; i < qnum; ++i)
	{
		int tmp;
		cin >> tmp;
		queries[i] = tmp;
	}

	// Output
	for (vector<int>::iterator it = queries.begin(); it != queries.end(); ++it)
		cout << pool[*it].first << " " << pool[*it].second << endl;

	return 0;
}