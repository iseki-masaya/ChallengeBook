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
#include <istream>

#define MAX_RA 10000000
#define MAX_L 100000000000

using namespace std;

bool is_prime_small[MAX_RA];
bool is_prime[MAX_L];

void segment_sieve(long long a,long long b)
{
	for (int i=0; (long long)i*i < b; ++i) {
		is_prime_small[i] = true;
	}
	for (int i=0; (long long)i < b-a; ++i) {
		is_prime[i] = true;
	}

	for (int i=2; (long long) i*i < b; ++i) {
		if (is_prime_small[i]) {
			for (int j=i*2; (long long) j*j<b; j+=i) {
				is_prime_small[j] = false;
			}
			for (long long j=max(2LL,(long long)(a+i-1)/i)*i; j<b; j += i) {
				is_prime[j-a] = false;
			}
		}
	}
}

int main(void) {
	long long a,b;
	cin >> a >> b;
	segment_sieve(a, b);
	long long ans = 0;
	for (long long i=0; i<b-a ; ++i) {
		if (is_prime[i]) {
			++ans;
		}
	}
	cout << ans;
	return 0;
}