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

#define MAX_M 100005
#define MAX_N 105

int N,M;
int A[MAX_N],C[MAX_N];
int dp[MAX_M];

void
solve()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=M; ++j) {
            if (dp[j] >= 0) {
                dp[j] = C[i];
            }
            else if (j < A[i] || dp[j - A[i]] <= 0) {
                dp[j] = -1;
            }
            else {
                dp[j] = dp[j - A[i]] - 1;
            }
        }
    }
    int res = 0;
    for (int i=1; i<=M; ++i) {
        if (dp[i] != -1) {
            ++res;
        }
    }
    printf("%d\n",res);
}

int
main()
{
    while (true) {
        scanf("%d %d",&N,&M);
        if (N == 0 && M == 0) {
            break;
        }
        for (int i=0; i<N; ++i) {
            scanf("%d",&A[i]);
        }
        for (int i=0; i<N; ++i) {
            scanf("%d",&C[i]);
        }
        solve();
    }
    return 0;
}
