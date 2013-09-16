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

#define INF 10000000000
#define EPS 1e-6

using namespace std;

#define MAX_V 2005
typedef pair<long long, int> P;
int V;
long long cost[MAX_V][MAX_V];

void
solve()
{
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,0));
    bool used[MAX_V];
    memset(used, false, sizeof(used));
    long long ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        ans = max(ans,p.first);
        for (int u=0; u<V; ++u) {
            if (!used[u] && cost[v][u] != INF) {
                que.push(P(cost[v][u],u));
            }
        }
    }
    printf("%lld\n",ans);
}

int
main()
{
    int M;
    scanf("%d %d",&V,&M);
    for (int i=0; i<V; ++i) {
        fill(cost[i], cost[i]+V, INF);
    }
    for (int i=0; i<M; ++i) {
        int a,b;
        long long c;
        scanf("%d %d %lld",&a,&b,&c);
        --a,--b;
        cost[a][b] = min(cost[a][b],c);
        cost[b][a] = cost[a][b];
    }
    solve();
}