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

#define MAX_H 45005

int A[MAX_H],B[MAX_H];
int N,M;

long long
mod_mult(long long a,long long b,long long m)
{
    long long res = 0;
    long long exp = a%m;
    while (b) {
        if (b&1) {
            res += exp;
            if (res > m) {
                res -= m;
            }
        }
        exp <<= 1;
        if (exp > m) {
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

void
solve()
{
    long long ans = 0;
    for (int i=0; i<N; ++i) {
        ans = ( ans + mod_exp(A[i], B[i], M) ) % M;
    }
    printf("%lld\n",ans);
}

int
main()
{
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; ++i) {
        scanf("%d",&M);
        scanf("%d",&N);
        for (int j=0; j<N; ++j) {
            scanf("%d %d",&A[j],&B[j]);
        }
        solve();
    }
}