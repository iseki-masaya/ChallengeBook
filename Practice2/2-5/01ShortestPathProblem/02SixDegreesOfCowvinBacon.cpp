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

#define INF (1<<28)

using namespace std;

#define MAX_N 305

int N,M;
int cost[MAX_N][MAX_N];

void
solve()
{
    for (int k=0; k<N; ++k) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
            }
        }
    }
    float ans = INF;
    for (int i=0; i<N; ++i) {
        float ret = 0;
        for (int j=0; j<N; ++j) {
            ret += cost[i][j];
        }
        ans = min(ans,ret/(N-1));
    }

    printf("%d\n",(int)(100.0*ans));
}

int
main()
{
    for (int i=0; i<MAX_N; ++i) {
        fill(cost[i], cost[i]+MAX_N, INF);
    }
    int tmp[MAX_N];
    scanf("%d %d",&N,&M);
    int cnt;
    for (int i=0; i<M; ++i) {
        scanf("%d",&cnt);
        for (int j=0; j<cnt; ++j) {
            scanf("%d",&tmp[j]);
            --tmp[j];
        }
        for (int j=0; j<cnt; ++j) {
            for (int k=j+1; k<cnt; ++k) {
                int a = tmp[j];
                int b = tmp[k];
                cost[a][b] = 1;
                cost[b][a] = 1;
            }
        }
    }
    for (int i=0; i<N; ++i) {
        cost[i][i] = 0;
    }
    solve();
}