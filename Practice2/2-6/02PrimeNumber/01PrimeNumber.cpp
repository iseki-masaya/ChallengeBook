/*
          mem   time
 bfs      464k  157ms
 dijkstra 384k  94ms
 */

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

//#define DEB

using namespace std;

#define MAX_N 1000000

vector<int> primes;
bool is_prime[MAX_N];

void
sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j=2*i; j<MAX_N; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

int
main()
{
    sieve();
    int p;
    while (scanf("%d",&p) != EOF) {
        int ans = (int)distance(primes.begin(),upper_bound(primes.begin(), primes.end(), p));
        printf("%d\n",ans);
    }
    return 0;
}