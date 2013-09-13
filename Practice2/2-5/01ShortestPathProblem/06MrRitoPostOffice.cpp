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

#define INF (1<<28)

using namespace std;

#define MAX_V 205
#define MAX_R 1005

int V,R;
int sea[MAX_V][MAX_V],land[MAX_V][MAX_V];
int dst[MAX_R];
int dp[MAX_R][MAX_V];

void
solve()
{
    for (int k=0; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                sea[i][j] = min(sea[i][j],sea[i][k]+sea[k][j]);
                land[i][j] = min(land[i][j],land[i][k]+land[k][j]);
            }
        }
    }

    for (int i=0; i<R; ++i) {
        fill(dp[i], dp[i]+MAX_V, INF);
    }
    dp[0][dst[0]] = 0;
    for (int k=0; k<R-1; ++k) {
        for (int i=0; i<V; ++i) {
            if (dp[k][i] != INF) {
                for (int j=0; j<V; ++j) {
                    dp[k+1][j] = min( dp[k+1][j] , dp[k][i] + land[dst[k]][i] + sea[i][j] + land[j][dst[k+1]] );
                }
                dp[k+1][i] = min( dp[k+1][i] , dp[k][i] + land[dst[k]][dst[k+1]]);
            }
        }
    }

    int ans = INF;
    for (int i=0; i<V; ++i) {
        ans = min( ans , dp[R-1][i] );
    }
    printf("%d\n",ans);
}

int
main()
{
    while (true) {
        int M;
        scanf("%d %d",&V,&M);
        if (V==0 && M==0) {
            break;
        }
        for (int i=0; i<V; ++i) {
            fill(sea[i], sea[i]+V, INF);
            fill(land[i], land[i]+V, INF);
        }
        for (int i=0; i<M; ++i) {
            int f,t,d;
            char m[8];
            scanf("%d %d %d %s",&f,&t,&d,m);
            --f,--t;
            if (m[0]=='L') {
                land[f][t] = min(land[f][t],d);
                land[t][f] = land[f][t];
            }
            else {
                sea[f][t] = min(sea[f][t],d);
                sea[t][f] = sea[f][t];
            }
        }
        for (int i=0; i<V; ++i) {
            sea[i][i] = land[i][i] = 0;
        }
        scanf("%d",&R);
        for (int i=0; i<R; ++i) {
            scanf("%d",&dst[i]);
            --dst[i];
        }
        solve();
    }

    return 0;
}