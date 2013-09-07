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

#define MAX_N 105
#define MAX_S 1005
#define MAX_RANGE (MAX_N * (2*MAX_S))
#define INF (1<<30)

int N;
int S[MAX_N],F[MAX_N];
int dp[2][MAX_RANGE];

void
solve()
{
    for (int i=0; i<2; ++i) {
        fill(dp[i], dp[i]+MAX_RANGE, -INF);
    }
    const int zero = MAX_RANGE/2;
    dp[0][zero] = dp[1][zero] = 0;
    for (int i=0; i<N; ++i) {
        int *nxt = dp[(i+1)&1];
        int *prv = dp[i&1];
        for (int j=0; j<MAX_RANGE; ++j) {
            if (prv[j] != -INF) {
                nxt[j] = max(prv[j],nxt[j]);
                nxt[j+S[i]] = max( prv[j+S[i]] , prv[j] + F[i]);
            }
        }
    }
    int ans = 0;
    for (int i=zero; i<MAX_RANGE; ++i) {
        if (dp[N&1][i] != -INF && dp[N&1][i] >= 0) {
            ans = max(ans , i-zero+dp[N&1][i]);
        }
    }
    printf("%d\n",ans);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&S[i],&F[i]);
    }
    solve();
}