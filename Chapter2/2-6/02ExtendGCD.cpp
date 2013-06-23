#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b, a%b);
}

int extgcd(int a,int b,int &x,int &y)
{
	int d = a;
	if (b!=0) {
		d = extgcd(b, a%b,y,x);
		y -= (a/b)*x; //
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

int main()
{
	int x = 0, y = 0;
	int d = extgcd(113, 54, x, y);
	cout << x << y << d;
}