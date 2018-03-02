#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// 1 Galleon = 17 Sickles
// 1 Sickles = 29 Knuts
const int G2S = 17;
const int S2K = 29;

struct Money
{
	int galleon, sickle, knut;
	Money() : galleon(0), sickle(0), knut(0) {}
	Money(int g, int s, int k) : galleon(g), sickle(s), knut(k) {}
	bool operator>(const Money &m)
	{
		if (galleon > m.galleon
			|| galleon == m.galleon && sickle > m.sickle
			|| galleon == m.galleon && sickle == m.sickle && knut > m.knut)
			return true;
		else
			return false;
	}
};

void formatMoney(Money &m)
{
	int rem = 0;
	if (m.knut >= S2K)
	{
		rem = m.knut / S2K;
		m.knut %= S2K;
		m.sickle += rem;
	}
	if (m.sickle >= G2S)
	{
		rem = m.sickle / G2S;
		m.sickle %= G2S;
		if (m.galleon >= 0)
			m.galleon += rem;
		else
			m.galleon -= rem;
	}
}

// Minus in Hogwarts
Money hMinus(Money m1, Money m2)
{
	bool take = false;	// need to take 1 from an upper level
	Money res;
	// knuts
	if (m1.knut >= m2.knut)
		res.knut = m1.knut - m2.knut;
	else
	{
		take = true;
		res.knut = S2K + m1.knut - m2.knut;
	}
	// sickles
	if (take)
	{
		--m1.sickle;
		take = false;
	}
	if (m1.sickle >= m2.sickle)
		res.sickle = m1.sickle - m2.sickle;
	else
	{
		take = true;
		res.sickle = G2S + m1.sickle - m2.sickle;
	}
	// galleons
	if (take)
	{
		--m1.galleon;
		take = false;
	}
	res.galleon = m1.galleon - m2.galleon;

	return res;
}

Money readMoney(const string &s)
{
	Money res;
	int pos1 = 0, pos2 = s.find('.');
	res.galleon = atoi(s.substr(pos1, pos2).c_str());
	pos1 = pos2 + 1;
	pos2 = s.find('.', pos1);
	res.sickle = atoi(s.substr(pos1, pos2 - pos1).c_str());
	res.knut = atoi(s.substr(pos2 + 1).c_str());
	formatMoney(res);
	return res;
}

string writeMoney(const Money &m)
{
	ostringstream oss;
	oss << m.galleon << "." << m.sickle << "." << m.knut;
	return oss.str();
}

int main()
{
	// Get data.
	string raw1, raw2;
	cin >> raw1 >> raw2;

	// Calculate.
	Money m1, m2;
	m1 = readMoney(raw1);
	m2 = readMoney(raw2);
	Money res;
	if (m1 > m2)
	{
		res = hMinus(m1, m2);
		res.galleon = -res.galleon;
	}
	else
		res = hMinus(m2, m1);

	// Output
	cout << writeMoney(res) << endl;

	return 0;
}