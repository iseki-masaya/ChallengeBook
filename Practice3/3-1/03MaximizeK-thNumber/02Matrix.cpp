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
long long M;

long long
calc(long long i,long long j)
{
    return i*i + 100000*i + j*j - 100000*j + i*j;
}

bool
check(long long m)
{
    long long cnt = 0;
    for (int j=0; j<N; ++j) {
        long long lb = 0 , ub = N+1 , mid;
        while (ub - lb > 1) {
            mid = (lb + ub)/2;
            if (calc(mid, j+1) > m) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        cnt += lb;
    }
    return cnt >= M;
}

void
solve()
{
    long long lb = -1000000000000 , ub = 1000000000000 , mid;
    while (ub - lb > 1) {
        mid = (ub + lb)/2;
        if (check(mid)) {
            ub = mid;
        }
        else {
            lb = mid;
        }
    }
    printf("%lld\n",ub);
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int i=0; i<num; ++i) {
        scanf("%d %lld",&N,&M);
        solve();
    }
    return 0;
}