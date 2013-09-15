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
#define EPS 1e-6

using namespace std;

#define MAX_V 1005

typedef pair<int, int> P;
int V;
int cost[MAX_V][MAX_V];

void
solve()
{
    priority_queue<P> que;
    bool used[MAX_V];
    memset(used, false, sizeof(used));
    que.push(P(0,0));

    long long ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();

        int v = p.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        ans += p.first;
        for (int u=0; u<V; ++u) {
            if (!used[u] && cost[v][u] != -1) {
                que.push(P(cost[v][u],u));
            }
        }
    }
    for (int i=0; i<V; ++i) {
        if (!used[i]) {
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n",ans);
}

int
main()
{
    int M;
    scanf("%d %d",&V,&M);
    memset(cost, -1, sizeof(cost));
    for (int i=0; i<M; ++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a , --b;
        cost[a][b] = max(c,cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    solve();
}