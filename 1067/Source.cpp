#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	// Get password and number of trials.
	string raw;
	stringstream iss;
	getline(cin, raw);
	iss << raw;
	string password;
	int num;
	iss >> password >> num;

	// Get trials and check.
	int nTrials = 0;	// number of actual trials
	getline(cin, raw);
	while (raw != "#")
	{
		nTrials++;
		if (nTrials <= num)
		{
			if (raw == password)
			{
				cout << "Welcome in" << endl;
				break;
			}
			else
			{
				cout << "Wrong password: " << raw << endl;
				if (nTrials == num)
				{
					cout << "Account locked" << endl;
					break;
				}
			}
		}
		getline(cin, raw);
	}

	return 0;
}