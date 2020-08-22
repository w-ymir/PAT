#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void derivation(map<int, int> &orig, map<int, int> &deriv)
{
	deriv.clear();
	for (map<int, int>::iterator p = orig.begin(); p != orig.end(); ++p)
	{
		if (p->first != 0)
		{
			deriv[p->first - 1] = p->first * p->second;
		}
		else
		{
			deriv[0] = 0;
		}
	}
	// Only store n*x^0 when there's nothing else.
	if (deriv.size() > 1 && deriv[0] == 0)
		deriv.erase(0);
}

string showPoly(const map<int, int> &poly)
{
	ostringstream oss;
	map<int, int>::const_reverse_iterator it = poly.crbegin();
	oss << it->second << " " << it->first;
	++it;
	for (; it != poly.crend(); ++it)
	{
		oss << " " << it->second << " " << it->first;
	}
	return oss.str();
}

int main()
{
	// Get raw input.
	string raw;
	getline(cin, raw);
	istringstream is(raw);
	// Store in map.
	map<int, int> poly;	// <int order, int factor>
	int tmp;
	while (is >> tmp)
	{
		int order, factor;
		factor = tmp;
		is >> order;
		if (poly.find(order) == poly.end())
			poly[order] = factor;
		else
			poly[order] += factor;
	}

	// Take derivatives.
	map<int, int> polyDeriv;
	derivation(poly, polyDeriv);

	// Output
	cout << showPoly(polyDeriv) << endl;

	return 0;
}