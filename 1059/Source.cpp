#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

bool isPrime(int n)
{
	bool result = true;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

int main()
{
	// Get number of competitors.
	int nCompetitors;
	cin >> nCompetitors;
	// Get the rank.
	map<string, int> rank;	// (Id, rank)
	for (int i = 1; i <= nCompetitors; ++i)
	{
		string curId;
		cin >> curId;
		rank.insert(make_pair(curId, i));
	}
	// Get number of queries.
	int nQueries;
	cin >> nQueries;
	// Get IDs and print.
	set<string> checked;
	for (int i = 0; i < nQueries; ++i)
	{
		string queryId, queryResult;
		cin >> queryId;
		if (checked.find(queryId) == checked.end())
		{
			if (rank.find(queryId) != rank.end())
			{
				if (rank.at(queryId) == 1)
				{
					queryResult = "Mystery Award";
				}
				else if (isPrime(rank.at(queryId)))
				{
					queryResult = "Minion";
				}
				else
				{
					queryResult = "Chocolate";
				}
				checked.insert(queryId);
			}
			else
			{
				queryResult = "Are you kidding?";
			}
		}
		else
		{
			queryResult = "Checked";
		}
		cout << queryId << ": " << queryResult << endl;
	}

	return 0;
}