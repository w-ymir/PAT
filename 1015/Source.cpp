#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Student
{
public:
	int id;
	int morality, talent;
	int total;
	int level;	// Level 0 ~ 4
	Student() : id(0), morality(0), talent(0), total(0) {}
	Student(int i, int m, int t, int lo, int hi) : id(i), morality(m), talent(t), total(m + t)
	{
		//if (morality < lo || talent < lo) { level = 4; return; }
		if (morality >= hi)
		{
			if (talent >= hi) level = 0;
			else level = 1;
		}
		else
		{
			if (morality >= talent) level = 2;
			else level = 3;
		}
	}
};

using DATA = list<Student>;

void storeItem(DATA *data, Student stu)
{
	if (stu.level == 4) return;
	data[stu.level].push_back(stu);
}

// Sort rules: 1. level (ascend); 2. total (descend); 3. id (ascend)
bool compare(const Student &stu1, const Student &stu2)
{
	if (stu1.level != stu2.level)
		return stu1.level < stu2.level;
	else if (stu1.total != stu2.total)
		return stu1.total > stu2.total;
	else if (stu1.morality != stu2.morality)
		return stu1.morality > stu2.morality;
	else
		return stu1.id < stu2.id;
}

int main()
{
	// Get basic info.
	int num, lower, upper;
	cin >> num >> lower >> upper;

	// Store data.
	DATA students[4];	// Students in Level 0~3.
	for (int i = 0; i < num; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b < lower || c < lower) continue;
		Student currStudent(a, b, c, lower, upper);
		storeItem(students, currStudent);
	}

	// Sort
	for (int i = 0; i < 4; ++i)
		students[i].sort(compare);

	// Output
	int count = 0;	// number of passed students
	for (int i = 0; i < 4; ++i)
		count += students[i].size();
	cout << count << endl;
	for (int i = 0; i < 4; ++i)
		for (DATA::const_iterator it = students[i].cbegin(); it != students[i].cend(); ++it)
			cout << it->id << " " << it->morality << " " << it->talent << endl;

	return 0;
}