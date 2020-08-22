#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<string> VS;

void parseChars(string &str, VS &vs)
{
	int pos = 0;
	while (pos < (int)str.size())
	{
		int p1 = str.find('[', pos);	// start point
		int p2 = str.find(']', p1);	// end point (excluded)
		if (p1 != string::npos && p2 != string::npos)
		{
			++p1;
			vs.push_back(str.substr(p1, p2 - p1));
			pos = p2 + 1;
		}
		else
			break;
	}
}

string formEmoji(int leftHand, int leftEye, int mouth, int rightEye, int rightHand, VS &vHand, VS &vEye, VS &vMouth)
{
	ostringstream oss;
	if (leftHand > (int)vHand.size() || rightHand > (int)vHand.size()
		|| leftEye > (int)vEye.size() || rightEye > (int)vEye.size()
		|| mouth > (int)vMouth.size()
		|| leftHand <= 0 || rightHand <= 0
		|| leftEye <= 0 || rightEye <= 0
		|| mouth <= 0)
		oss << "Are you kidding me? @\\/@";
	else
		oss << vHand[leftHand - 1] << "(" << vEye[leftEye - 1] << vMouth[mouth - 1] << vEye[rightEye - 1] << ")" << vHand[rightHand - 1];
	return oss.str();
}

int main()
{
	// Get charsets.
	VS hand, eye, mouth;
	string raw;
	getline(cin, raw);
	parseChars(raw, hand);
	getline(cin, raw);
	parseChars(raw, eye);
	getline(cin, raw);
	parseChars(raw, mouth);
	cin.sync();
	cin.clear();

	// Get number of queries.
	int num;
	cin >> num;
	// Read and write.
	for (int i = 0; i < num; ++i)
	{
		int n1, n2, n3, n4, n5;
		cin >> n1 >> n2 >> n3 >> n4 >> n5;
		cout << formEmoji(n1, n2, n3, n4, n5, hand, eye, mouth) << endl;
	}

	return 0;
}