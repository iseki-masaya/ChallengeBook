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
#include <time.h>
#include <numeric>

using namespace std;

#define MAX_P 40005
#define INF (1<<26)

int a[MAX_P];
int P;

void
solve()
{
    int dp[MAX_P];
    fill(dp, dp + P, INF);
    for (int i=0; i<P; ++i) {
        *lower_bound(dp, dp+P, a[i]) = a[i];
    }
    printf("%ld\n",lower_bound(dp, dp+P, INF) - dp);
}

int
main()
{
    int T;
    scanf("%d",&T);
    for (int t=0; t<T; ++t) {
        scanf("%d",&P);
        for (int i=0; i<P; ++i) {
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}