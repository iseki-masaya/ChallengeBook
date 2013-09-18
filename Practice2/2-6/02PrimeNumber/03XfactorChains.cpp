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

int N;

long long
factorial(int n)
{
    long long res = 1;
    for (int i=1; i<=n; ++i) {
        res *= i;
    }
    return res;
}

void
s_solve()
{
    map<int, int> factor;
    int t = N;
    for (int i=2; i*i<=N; ++i) {
        while (t%i == 0) {
            factor[i]++;
            t /= i;
        }
    }
    if (t!=1) {
        factor[t]++;
    }

    int les = 0;
    for (map<int, int>::iterator it = factor.begin(); it != factor.end(); ++it) {
        les += (*it).second;
    }
    long long p = factorial(les);
    for (map<int, int>::iterator it = factor.begin(); it != factor.end(); ++it) {
        p /= factorial((*it).second);
    }
    printf("%d %lld\n",les,p);
}

void
solve()
{
    vector<int> factor;
    int t = N;
    for (int i=2; i*i<=N && t!= 1; ++i) {
        while (t%i == 0) {
            factor.push_back(i);
            t /= i;
        }
    }
    if (t != 1) {
        factor.push_back(t);
    }

    int cnt = 0;
    do {
        ++cnt;
    } while (next_permutation(factor.begin(), factor.end()));

    printf("%d %d\n",(int)factor.size(),cnt);
}

int
main()
{
    while (scanf("%d",&N) != EOF) {
        s_solve();
    }
    return 0;
}