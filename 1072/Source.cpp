#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Get basic info.
	int nStudents, nConfiscated;
	cin >> nStudents >> nConfiscated;
	// Get confiscated props.
	set<string> props;
	for (int i = 0; i < nConfiscated; i++)
	{
		string curProp;
		cin >> curProp;
		props.insert(curProp);
	}

	// Get student props.
	int confStudents = 0, confProps = 0;
	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int nProps;
		cin >> name >> nProps;
		vector<string> curConfProps;
		curConfProps.reserve(nProps);
		for (int j = 0; j < nProps; j++)
		{
			string curProp;
			cin >> curProp;
			if (props.find(curProp) != props.end())	// confiscated prop found
			{
				curConfProps.push_back(curProp);
			}
		}
		if (curConfProps.size() > 0)
		{
			confStudents++;
			confProps += curConfProps.size();
			cout << name << ":";
			for (auto prop : curConfProps)
				cout << " " << prop;
			cout << endl;
		}
	}
	// Print statistics.
	cout << confStudents << " " << confProps << endl;

	return 0;
}