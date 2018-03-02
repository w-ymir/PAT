#include <iostream>
#include <string>

using namespace std;

// Get info for printing a sand glass.
// orig -> number given
// first <- length of line 1
// rem <- number of unused
void sandGlassInfo(int orig, int &first, int &rem)
{
	if (orig == 0) { first = 0; rem = 0; return; }
	
	int level = -1;	// chars in current level
	int curr = orig + 1;	// remaining chars
	while (curr > 0)
	{
		level += 2;
		curr -= level * 2;
	}
	if (curr < 0)
	{
		curr += level * 2;
		level -= 2;
	}
	
	first = level;
	rem = curr;
}

// Print current line of sand glass
void PrintSadGlassLine(int space, int star, char ch)
{
	string strSpace(space, ' '), strStar(star, ch);
	cout << strSpace << strStar << endl;
}

// Print sand glass
// start -> number of chars in line 1
void PrintSandGlass(int start, char ch)
{
	if (start == 0) return;
	
	// upper half
	int curr = start;
	do
	{
		PrintSadGlassLine((start - curr) / 2, curr, ch);
		curr -= 2;
	} while (curr > 0);
	// lower half
	curr = 3;
	while (curr <= start)
	{
		PrintSadGlassLine((start - curr) / 2, curr, ch);
		curr += 2;
	}
}

int main()
{
	// Get number
	int num;
	char ch;
	cin >> num >> ch;
	
	// Process
	int line1, remainder;
	sandGlassInfo(num, line1, remainder);
	
	// Draw
	PrintSandGlass(line1, ch);
	
	// Print remainder EVEN IF IT IS ZERO
	//if (remainder != 0)
		cout << remainder << endl;
	
	return 0;
}
