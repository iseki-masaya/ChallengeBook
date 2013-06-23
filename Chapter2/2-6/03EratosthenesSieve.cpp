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
#include <stack>

using namespace std;

#define MAX_N 10000000

int prime[MAX_N] = {0};
bool is_prime[MAX_N];

int sieve(int n)
{
	int p=0;
	for (int i=0; i<=n; ++i) {
		is_prime[i] = true;
	}
	is_prime[0] = false; is_prime[1] = false;

	for (int i=2; i<=n; ++i) {
		if (is_prime[i]) {
			prime[++p] = i;
			for (int j=i+i; j<=n; j+=i) {
				is_prime[j] = false;
			}
		}
	}
	return p;
}

int main()
{
	int n;
	cin >> n;
	cout << sieve(n) << endl;
}