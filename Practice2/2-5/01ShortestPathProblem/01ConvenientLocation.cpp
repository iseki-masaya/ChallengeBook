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

#define MAX_N 15

int N,K;
int cost[MAX_N][MAX_N];

void
init()
{
    for (int i=0; i<MAX_N; ++i) {
        fill(cost[i], cost[i]+MAX_N, INF);
        cost[i][i] = 0;
    }
}

void
solve()
{
    for (int k=0; k<K; ++k) {
        for (int i=0; i<K; ++i) {
            for (int j=0; j<K; ++j) {
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
            }
        }
    }
    int ans = INF;
    int pos = -1;
    for (int i=0; i<K; ++i) {
        int res = 0;
        for (int j=0; j<K; ++j) {
            res += cost[i][j];
        }
        if (ans > res) {
            pos = i;
            ans = res;
        }
    }
    printf("%d %d\n",pos,ans);
}

int
main()
{
    for (;;) {
        scanf("%d",&N);
        if (N==0) {
            break;
        }
        init();
        K = 0;
        for (int i=0; i<N; ++i) {
            int f,t,c;
            scanf("%d %d %d",&f,&t,&c);
            cost[f][t] = c;
            cost[t][f] = c;
            K = max(K,max(f,t));
        }
        ++K;
        solve();
    }
    return 0;
}