#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <istream>

using namespace std;

#define SIZE 65001

bool is_prime[SIZE];
bool is_carmichael[SIZE];

long long mod_pow(long long x,long long n,long long mod)
{
	if (n == 0) {
		return 1;
	}
	long long res = mod_pow(x*x%mod, n/2, mod);
	if (n & 1) {
		res = res * x % mod;
	}
	return res;
}

void sieve()
{
	for (int i=0; i<=SIZE; ++i) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i<=SIZE; ++i) {
		if (is_prime[i]) {
			for (int j = 2*i; j <= SIZE; j+=i) {
				is_prime[j] = false;
			}
		}
	}
}

bool is_passed(int n)
{
	for (int a = 2; a < n; ++a) {
		if (mod_pow(a, n, n) != a) {
			return false;
		}
	}
	return true;
}

void carmichael()
{
	for (int i = 3; i < SIZE; ++i) {
		is_carmichael[i] = !is_prime[i] && is_passed(i);
	}
}

int main(void) {
	sieve();
	carmichael();
	long long x;
	scanf("%lld",&x);
	while (x!=0) {
		if (is_carmichael[x]) {
			printf("The number %lld is a Carmichael number.\n",x);
		}
		else {
			printf("%lld is normal.\n",x);
		}
		scanf("%lld",&x);
	}
	return 0;
}