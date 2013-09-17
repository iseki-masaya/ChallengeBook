#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

const int MOD = 1000000007;

long long
gcd(long long a,long long b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

long long
mod_mult(long long a,long long b,long long m)
{
  long long res = 0;
    long long mir = a%m;
    while (b) {
        if (b&1) {
            res += mir;
            if (res > m) {
                res -= m;
            }
        }
        mir <<= 1;
        if (mir > m) {
            mir -= m;
        }
        b >>= 1;
    }
    return res;
}

long long
mod_exp(long long a,long long b,long long m)
{
    long long res = 1;
    long long mir = a%m;
    while (b) {
        if (b&1) {
            res = mod_mult(res, mir,m);
        }
        mir = mod_mult(mir, mir,m);
        b >>= 1;
    }
    return res;
}

bool
miller_rabin(long long n,int t)
{
    if (n <  2) return false;
    if (n == 2) return true;
    if (!(n&1)) return false;

    long long q = n-1;
    int k = 0;
    while ((q&1) == 0) {
        k++;
        q >>= 1;
    }
    for (int i=0; i < t; ++i) {
        long long a = rand() % (n-1) + 1;
        long long x = mod_exp(a, q, n);
        if (x==1) {
            continue;
        }
        bool found = false;
        for (int j=0; j<k; ++j) {
            if ( x == n-1) {
                found = true;
                break;
            }
            x = mod_mult(x, x, n);
        }
        if (found) {
            continue;
        }
        return false;
    }
    return true;
}

long long
pollard_rho(long long n,int c)
{
    long long x = 2;
    long long y = 2;
    long long d = 1;
    while (d == 1) {
        x = mod_mult(x, x, n) + c;
        y = mod_mult(y, y, n) + c;
        y = mod_mult(y, y, n) + c;
        d = gcd( n , (x-y > 0 ? x-y : y-x) );
    }
    if (d == n) {
        return pollard_rho(n, c+1);
    }
    return d;
}

const int MAX_PRIME = 200000;
vector<int> primes;
bool is_prime[MAX_PRIME];

void
sieve()
{
    fill(is_prime, is_prime+MAX_PRIME, true);
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<=MAX_PRIME; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j=i+i; j <= MAX_PRIME; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

bool
isPrime(long long n)
{
    if (n <= MAX_PRIME) return is_prime[n];
    return miller_rabin(n, 20);
}

void
factorize(long long n,map<long long, int> &factor)
{
    if (isPrime(n)) {
        factor[n]++;
    }
    else {
        for (int i=0; i<primes.size(); ++i) {
            int p = primes[i];
            while (n % p == 0) {
                factor[p]++;
                n /= p;
            }
        }
        if (n != 1) {
            if (isPrime(n)) {
                factor[n]++;
            }
            else {
                long long d = pollard_rho(n, 1);
                factor[d]++;
                factorize(n/d, factor);
            }
        }
    }
}

void
solve(long long g,long long l)
{
    long long c = l/g;
    map<long long, int> factor;
    factorize(c, factor);

    vector<long long> mult_factor;
    for (map<long long, int>::iterator it = factor.begin(); it != factor.end(); ++it) {
        long long res = 1;
        while (it->second) {
            res *= it->first;
            it->second --;
        }
        mult_factor.push_back(res);
    }

    long long mnsum = 1e18 , mnx = 1 , mny = c;
    int lim = (1 << mult_factor.size());
    for (int mask=0; mask<lim; ++mask) {
        long long x = 1;
        for (int i=0; i<mult_factor.size(); ++i) {
            if (mask & (1 << i)) {
                x *= mult_factor[i];
            }
        }
        long long y = c/x;
        if (x < y && x+y < mnsum) {
            mnsum = x + y;
            mnx = x;
            mny = y;
        }
    }
    printf("%lld %lld\n",mnx*g,mny*g);
}

int
main()
{
    sieve();
    long long g,l;
    while (scanf("%lld %lld",&g,&l) != EOF) {
        solve(g, l);
    }
    return 0;
}