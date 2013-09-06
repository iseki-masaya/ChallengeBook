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

#define MAX_N 2005
#define INF (1<<30)

int N;
int T[2][MAX_N];
int H[MAX_N];
int dp[2][MAX_N];

void
solve()
{
    int res = INF;
    sort(H, H+N);
    for (int dir=0; dir<2; ++dir) {
        memset(dp, 0, sizeof(dp));
        int *A = T[dir];
        for (int i=0; i<N; ++i) {
            int *nxt = dp[(i+1)&1];
            int *prv = dp[i&1];
            int mn = INF;
            for (int j=0; j<N; ++j) {
                mn = min(mn,prv[j]);
                nxt[j] = mn + abs(A[i]-H[j]);
            }
        }
        for (int i=0; i<N; ++i) {
            res = min(res,dp[N&1][i]);
        }
    }
    printf("%d\n",res);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        int t;
        scanf("%d",&t);
        T[0][i] = T[1][(N-1)-i] = H[i] = t;
    }
    solve();
    return 0;
}