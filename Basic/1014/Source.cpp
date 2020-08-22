#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>	// max
#include <utility>	// make_pair
#include <vector>
#include <iomanip>

using namespace std;

const vector<string> Weekday = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

// Get weekday character index & number
pair<int, int> getWeekday(const string &s1, const string &s2)
{
	int length = min(s1.size(), s2.size());
	for (int i = 0; i < length; ++i)
	{
		char tmp = s1.at(i);
		if (tmp == s2.at(i) && tmp >= 'A' && tmp <= 'G')
			return make_pair(i, tmp - 'A' + 1);
	}
	return make_pair(-1, 0);
}

int charToHour(char c)
{
	int result = -1;
	if (c >= '0' && c <= '9')
		result = c - '0';
	else if (c >= 'A' && c <= 'N')
		result = c - 'A' + 10;
	return result;
}

int getHour(const string &s1, const string &s2, const int pos)
{
	int length = min(s1.size(), s2.size());
	for (int i = pos; i < length; ++i)
	{
		char tmp = s1.at(i);
		if (tmp == s2.at(i))
			if (tmp >= '0' && tmp <= '9'
				|| tmp >= 'A' && tmp <= 'N')
				return charToHour(tmp);
	}
	return -1;
}

int getMinute(const string &s1, const string &s2)
{
	int length = min(s1.size(), s2.size());
	for (int i = 0; i < length; ++i)
	{
		char tmp = s1.at(i);
		if (tmp == s2.at(i) && (tmp >= 'A' && tmp <= 'Z' || tmp >= 'a' && tmp <= 'z'))
			return i;
	}
	return -1;
}

string timeToString(int d, int h, int m)
{
	ostringstream oss;
	oss << Weekday.at(d - 1) << " "
		<< setw(2) << setfill('0') << h
		<< ":" << setw(2) << setfill('0') << m;
	return oss.str();
}

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	pair<int, int> tmp = getWeekday(s1, s2);
	int day = tmp.second;
	int hour = getHour(s1, s2, tmp.first + 1);
	int minute = getMinute(s3, s4);

	cout << timeToString(day, hour, minute) << endl;

	return 0;
}