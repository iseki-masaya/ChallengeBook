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

long long a,p;

long long
mod_mult(long long a,long long b,long long m)
{
    long long res = 0;
    long long exp = a%m;
    while (b) {
        if (b&1) {
            res += exp;
            if (res >= m) {
                res -= m;
            }
        }
        exp <<= 1;
        if (exp >= m) {
            exp -= m;
        }
        b >>= 1;
    }
    return res;
}

long long
mod_exp(long long a,long long b,long long m)
{
    long long res = 1;
    long long exp = a%m;
    while (b) {
        if (b&1) {
            res = mod_mult(res, exp, m);
        }
        exp = mod_mult(exp, exp, m);
        b >>= 1;
    }
    return res;
}

bool
is_prime(long long p)
{
    if (p==2) {
        return true;
    }
    if (p < 2 || (p&1) == 0) {
        return false;
    }
    for (int i=2; i*i<=p; ++i) {
        if (p%i == 0) {
            return false;
        }
    }
    return true;
}

void
solve()
{
    if (!is_prime(p) && a == mod_exp(a, p, p)) {
        puts("yes");
    }
    else {
        puts("no");
    }
}

int
main()
{
    while (true) {
        scanf("%lld %lld",&p,&a);
        if (p == 0 && a == 0) {
            break;
        }
        solve();
    }
}