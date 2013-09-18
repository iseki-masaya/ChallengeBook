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

#define MAX_P 1000005

int N;

vector<int> primes;
bool is_prime[MAX_P];
vector<int> cmp;

void
sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    for (int i=1; 4*i+1 < MAX_P; ++i) {
        int p = 4*i + 1;
        if (is_prime[p]) {
            primes.push_back(p);
            for (int j=2*p; j < MAX_P; j+=p) {
                is_prime[j] = false;
            }
        }
    }
}

void
make()
{
    for (int i=0; primes[i]*primes[i]<MAX_P; ++i) {
        for (int j=i; primes[i]*primes[j]<MAX_P; ++j) {
            long long k = primes[i]*primes[j];
            cmp.push_back((int)k);
        }
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
}

void
solve()
{
    int cnt = (int)distance(cmp.begin(), upper_bound(cmp.begin(), cmp.end(), N));
    printf("%d %d\n",N,cnt);
}

int
main()
{
    sieve();
    make();
    while (true) {
        scanf("%d",&N);
        if (N==0) {
            break;
        }
        solve();
    }
    return 0;
}