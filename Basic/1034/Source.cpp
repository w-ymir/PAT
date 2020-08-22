#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// Fraction
struct Frac
{
	long long num, denom;	// numerator & denominator
	Frac() : num(0), denom(1) {}
	Frac(long long a) : num(a), denom(1) {}
	Frac(long long a, long long b) : num(a), denom(b)
	{
		if (a == 0 && b != 0)	// 0/x -> 0/1 (0)
			denom = 1;
		if (b == 0)	// x/0 -> 0/0 (Inf)
			num = 0;
	}
};

// llabs for "long long" type
long long llabs(long long n)
{
	if (n < 0)
		n = -n;
	return n;
}

// Get greatest common divisor (gcd)
long long gcd(long long a, long long b)
{
	if (a == 0 || b == 0)
		return 0;

	a = llabs(a);
	b = llabs(b);
	if (a < b)
	{
		long long tmp = a;
		a = b;
		b = tmp;
	}

	long long remainder = b;
	do
	{
		remainder = a % b;
		a = b;
		b = remainder;
	} while (remainder != 0);

	return a;
}
// Get lowest common multiple (lcm)
long long lcm(const long long a, const long long b)
{
	if (a == 0 || b == 0)
		return 0;

	long long x = gcd(a, b);
	if (x == 0) return 0;
	return a * b / x;
}

// Simplify fraction
void simplify(Frac &frac)
{
	long long divisor = gcd(frac.num, frac.denom);
	if (divisor == 0) return;

	frac.num /= divisor;
	frac.denom /= divisor;
}

// Read fraction
Frac readFrac(const string &str)
{
	int a, b;
	int pos = str.find('/');
	a = atoi(str.substr(0, pos).c_str());
	b = atoi(str.substr(pos + 1).c_str());
	Frac tmp(a, b);
	simplify(tmp);
	return tmp;
}
// Write Fraction
string writeFrac(const Frac &frac)
{
	if (frac.denom == 0)
		return "Inf";
	else if (frac.num == 0)
		return "0";

	ostringstream oss;
	long long posNum = llabs(frac.num);	// numerator part without sign
	if (frac.num < 0)	// show negative sign
		oss << "(-";
	if (posNum >= frac.denom)	// show whole number if any
	{
		oss << posNum / frac.denom;
	}
	if (frac.denom != 1)	// show fraction part if any
	{
		if (posNum > frac.denom)
			oss << " ";
		oss << posNum % frac.denom << "/" << frac.denom;
	}
	if (frac.num < 0)
		oss << ")";
	return oss.str();
}

// Fraction plus
Frac fPlus(const Frac &f1, const Frac &f2)
{
	if (f1.denom == 0 || f2.denom == 0)
		return Frac(0, 0);
	else
	{
		if (f1.num == 0)
			return f2;
		else if (f2.num == 0)
			return f1;
	}

	long long mult = lcm(f1.denom, f2.denom);
	Frac tmp1, tmp2;
	tmp1 = Frac(f1.num * (mult / f1.denom), mult);
	tmp2 = Frac(f2.num * (mult / f2.denom), mult);
	Frac res(tmp1.num + tmp2.num, mult);
	simplify(res);
	return res;
}
// Fraction minus
Frac fMinus(const Frac &f1, const Frac &f2)
{
	Frac tmp(-f2.num, f2.denom);
	return fPlus(f1, tmp);
}
// Fraction multiplication
Frac fMultiply(const Frac &f1, const Frac &f2)
{
	if (f1.denom == 0 || f2.denom == 0)
		return Frac(0, 0);
	else if (f1.num == 0 || f2.num == 0)
		return Frac(0, 1);

	Frac res(f1.num * f2.num, f1.denom * f2.denom);
	simplify(res);
	return res;
}
// Fraction division
Frac fDivide(const Frac &f1, const Frac &f2)
{
	if (f2.num == 0 || f2.denom == 0)
		return Frac(0, 0);

	Frac tmp(f2);
	long long t = tmp.num;
	if (t > 0)
	{
		tmp.num = tmp.denom;
		tmp.denom = t;
	}
	else
	{
		tmp.num = -tmp.denom;
		tmp.denom = -t;
	}
	return fMultiply(f1, tmp);
}

int main()
{
	// Get data.
	string raw1, raw2;
	cin >> raw1 >> raw2;

	// Get things ready.
	Frac f1, f2;
	f1 = readFrac(raw1);
	f2 = readFrac(raw2);

	// Calculate and print
	Frac res;
	// Plus
	cout << writeFrac(f1) << " + " << writeFrac(f2) << " = " << writeFrac(fPlus(f1, f2)) << endl;
	// Minus
	cout << writeFrac(f1) << " - " << writeFrac(f2) << " = " << writeFrac(fMinus(f1, f2)) << endl;
	// Multiply
	cout << writeFrac(f1) << " * " << writeFrac(f2) << " = " << writeFrac(fMultiply(f1, f2)) << endl;
	// Divide
	cout << writeFrac(f1) << " / " << writeFrac(f2) << " = " << writeFrac(fDivide(f1, f2)) << endl;

	return 0;
}
