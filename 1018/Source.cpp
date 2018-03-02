#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>	// std::greater

using namespace std;

// Judge if Party A win (1) or lose(-1), or it is a draw (0).
// B - bu (paper)
// C - chui (rock)
// J - jian (scissors)
int judge(char a, char b)
{
	if (a == b)
		return 0;
	if (a == 'B' && b == 'C'
		|| a == 'C' && b == 'J'
		|| a == 'J' && b == 'B')
		return 1;
	else return -1;
}

// Store current hand to winning record.
void storeToRecord(char c, vector<int> &rec)
{
	switch (c)
	{
	case 'B':
		++rec[0];
		break;
	case 'C':
		++rec[1];
		break;
	case 'J':
		++rec[2];
		break;
	default:
		break;
	}
}

// Convert order number (in vector<int>) to char (for hand).
char orderToHand(size_t n)
{
	char c;
	switch (n)
	{
	case 0:
		c = 'B';
		break;
	case 1:
		c = 'C';
		break;
	case 2:
		c = 'J';
		break;
	default:
		c = '?';
		break;
	}
	return c;
}

// Analyse the current round.
// data - number of lose/draw/win for Party A.
// recordX - win as B/C/J for Party X.
void analyse(char a, char b, vector<int> &data, vector<int> &recordA, vector<int> &recordB)
{
	int result = judge(a, b);
	++data[result + 1];

	switch (result)
	{
	case 1:
		storeToRecord(a, recordA);
		break;
	case -1:
		storeToRecord(b, recordB);
		break;
	default:
		break;
	}
}


int main()
{
	// Get data.
	int num;
	cin >> num;

	// Process.
	vector<int> partyAData{ 0,0,0 };	// number of lose/draw/win for Party A
	vector<int> partyARecord{ 0, 0, 0 }, partyBRecord{ 0, 0, 0 };	// win as B/C/J for Party A/B
	for (int i = 0; i < num; ++i)
	{
		char handA, handB;
		cin >> handA >> handB;
		analyse(handA, handB, partyAData, partyARecord, partyBRecord);
	}

	// Output
	cout << partyAData[2] << " " << partyAData[1] << " " << partyAData[0] << endl;
	cout << partyAData[0] << " " << partyAData[1] << " " << partyAData[2] << endl;

	char handA = orderToHand(max_element(partyARecord.begin(), partyARecord.end()) - partyARecord.begin());
	char handB = orderToHand(max_element(partyBRecord.begin(), partyBRecord.end()) - partyBRecord.begin());
	cout << handA << " " << handB << endl;

	return 0;
}