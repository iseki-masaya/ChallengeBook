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

#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define MAX_N 10500

bool is_prime[MAX_N];
vector<int> primes;

void
sieve(int n)
{
    memset(is_prime, false, sizeof(is_prime));
    for (int i=2; i<n; ++i) {
        if (!is_prime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<n; j+=i) {
                is_prime[j] = true;
            }
        }
    }
}

int N,V;

bool
init()
{
    scanf("%d",&V);
    return V>0;
}

void
solve()
{
    int sum = primes[0] , l = 0 , r = 0;
    int ans = 0;
    for (;;) {
        while (r < N && primes[r] < V && sum < V) {
            sum += primes[++r];
        }
        if (sum == V) {
            ++ans;
        }
        if (sum < V || primes[r] > V) {
            break;
        }
        sum -= primes[l++];
    }
    printf("%d\n",ans);
}

int
main()
{
    sieve(MAX_N);
    N = (int)primes.size();
    while (init()) {
        solve();
    }
    return 0;
}