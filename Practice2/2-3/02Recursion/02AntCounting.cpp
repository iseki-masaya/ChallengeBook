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

#define MAX_T 1005
#define MAX_A 1000005
#define MOD 1000000

int T,A,S,B;
int C[MAX_T];
int dp[2][MAX_A];

void
solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[1][0] = 1;

    for (int i=1; i<=T; ++i) {
        int *nxt  = dp[i%2];
        int *prev = dp[(i+1)%2];
        for (int j=1; j<=B; ++j) {
            if (j - 1 - C[i] >= 0) {
                nxt[j] = (nxt[j-1] + prev[j] - prev[j - 1 - C[i]] + MOD)%MOD;
            }
            else {
                nxt[j] = (nxt[j-1] + prev[j])%MOD;
            }
        }
    }

    int res = 0;
    for (int i=S; i<=B; ++i) {
        res = (res + dp[T%2][i])%MOD;
    }

    printf("%d\n",res);
}

int
main()
{
    memset(C, 0, sizeof(C));
    scanf("%d %d %d %d",&T,&A,&S,&B);
    for (int i=0; i<A; ++i) {
        int n;
        scanf("%d",&n);
        C[n]++;
    }
    solve();
}