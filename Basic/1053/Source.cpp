/*
测试点 	结果 	用时(ms) 	内存(kB) 	得分/满分
0 	答案正确 	3 	384 	10/10
1 	答案错误 	8 	384 	0/5
2 	答案错误 	87 	1536 	0/2
3 	答案正确 	6 	380 	1/1
4 	答案正确 	7 	384 	1/1
5 	答案正确 	6 	384 	1/1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	// Get number of houses, threshold power value, threshold days
	int nHouse, tDays;
	double tValue;
	cin >> nHouse >> tValue >> tDays;
	// Get data.
	vector<vector<double>> data(nHouse);
	for (int i = 0; i < nHouse; ++i)
	{
		// Get number of watch days.
		int wDays;
		cin >> wDays;
		data[i].reserve(wDays);
		for (int j = 0; j < wDays; ++j)
		{
			double tmp;
			cin >> tmp;
			data[i].push_back(tmp);
		}
	}

	// Analyse.
	int probVacancy = 0, vacancy = 0;	// number of probably vacancy & vacancy
	for (size_t i = 0; i < data.size(); ++i)
	{
		int lowPowerDays = 0;
		for (size_t j = 0; j < data[i].size(); ++j)
			if (data[i][j] < tValue)
				++lowPowerDays;
		if (lowPowerDays > (int)data[i].size() / 2)
		{
			if (lowPowerDays > tDays)
				++vacancy;
			else
				++probVacancy;
		}
	}

	// Output
	cout << fixed << setprecision(1) << (100.0 * probVacancy / nHouse) << "% "
		<< fixed << setprecision(1) << (100.0 * vacancy / nHouse) << "%" << endl;

	return 0;
}