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

int gcd(int a,int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	cout << gcd(53965461, 45635);
}