#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	string id;
	int score;
};

bool compareScore(Student a, Student b)
{
	return a.score < b.score;
}

int main()
{
	// Read number of items.
	int num;
	cin >> num;
	cin.ignore();

	// Store data.
	vector<Student> student;
	for (int i = 1; i <= num; ++i)
	{
		string str;
		getline(cin, str);
		istringstream is{ str };
		Student curStu;
		is >> curStu.name >> curStu.id >> curStu.score;
		student.push_back(curStu);
	}

	// Get max & min.
	vector<Student>::const_iterator stuMax, stuMin;
	stuMax = max_element(student.cbegin(), student.cend(), compareScore);
	stuMin = min_element(student.cbegin(), student.cend(), compareScore);

	// Print
	cout << stuMax->name << " " << stuMax->id << endl
		<< stuMin->name << " " << stuMin->id << endl;

	return 0;
}