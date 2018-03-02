#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int CLK_TCK = 100;

void ticksToTime(int tck, int &h, int &m, int &s)
{
	// Tranfer to time
	int t = tck / CLK_TCK;
	if (tck % CLK_TCK >= (CLK_TCK + 1) / 2)
		++t;
	// Get h, m, s
	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t % 60;
}

string formatTime(int h, int m, int s)
{
	ostringstream oss;
	oss << setw(2) << setfill('0') << h << ":"
		<< setw(2) << setfill('0') << m << ":"
		<< setw(2) << setfill('0') << s;
	return oss.str();
}

int main(int argc, char** argv)
{
	// Get data.
	int t1, t2;
	cin >> t1 >> t2;
	
	// Get h, m, s
	int h, m, s;
	ticksToTime(t2 - t1, h, m, s);
	
	// Print
	cout << formatTime(h, m, s) << endl;
	
	return 0;
}
