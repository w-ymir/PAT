#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

const int SCALE = 13;
const char *s1[] = { "", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const char *s2[] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
const string v0("tret");
const vector<string> v1(s1, s1 + SCALE);
const vector<string> v2(s2, s2 + SCALE);

string earth2mars(string &earth)
{
	int n = atoi(earth.c_str());
	ostringstream oss;
	if (n == 0)
		oss << v0;
	else
	{
		if (n / SCALE != 0)
		{
			oss << v2[n / SCALE];
			if (n % SCALE != 0)
				oss << " ";
		}
		oss << v1[n % SCALE];
	}
	return oss.str();
}

string mars2earth(string &mars)
{
	if (mars == v0)
		return "0";

	istringstream iss(mars);
	vector<string> vs;
	string str;
	while (iss >> str)
		vs.push_back(str);
	ostringstream oss;
	if (vs.size() == 2)
	{
		vector<string>::const_iterator it1 = find(v2.begin(), v2.end(), vs[0]),
			it2 = find(v1.begin(), v1.end(), vs[1]);
		oss << SCALE * distance(v2.begin(), it1) + distance(v1.begin(), it2);
	}
	else
	{
		vector<string>::const_iterator it1 = find(v1.begin(), v1.end(), vs[0]);
		vector<string>::const_iterator it2 = find(v2.begin(), v2.end(), vs[0]);
		if (it1 != v1.end())
			oss << distance(v1.begin(), it1);
		else if (it2 != v2.end())
			oss << SCALE * distance(v2.begin(), it2);
		else
			oss << "?";
	}
	return oss.str();
}

int main()
{
	// Get number of items.
	int num;
	cin >> num;
	cin.get();

	// Read data.
	vector<string> data(num);
	for (int i = 0; i < num; ++i)
	{
		string tmp;
		getline(cin, tmp);
		data[i] = tmp;
	}

	// Process.
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (isdigit(data[i][0]))
			cout << earth2mars(data[i]) << endl;
		else
			cout << mars2earth(data[i]) << endl;
	}

	return 0;
}