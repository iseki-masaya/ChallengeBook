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

#define MAX_V 10005
struct edge {
    int from,to,dist,cost;
    edge(){}
    edge(int f,int t,int d,int c) : from(f),to(t),dist(d),cost(c){}
};

typedef pair<int, int> P;
vector<edge> G[MAX_V];

int V;

bool
operator < (const edge &lhs,const edge &rhs)
{
    return lhs.dist != rhs.dist ? lhs.dist > rhs.dist : lhs.cost > rhs.cost;
}

int
cost_dijkstra(int s)
{
    priority_queue<edge> que;
    que.push(edge(0,0,0,0));
    bool used[MAX_V] = {false};

    int ans = 0;
    while (!que.empty()) {
        edge e = que.top(); que.pop();
        int v = e.to;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        ans += e.cost;

        for (int u=0; u<G[v].size(); ++u) {
            edge ce = G[v][u];
            que.push(edge(ce.from,ce.to,e.dist+ce.dist,ce.cost));
        }
    }
    return ans;
}

void
solve()
{
    int ans = cost_dijkstra(0);
    printf("%d\n",ans);
}

int main()
{
    while (true) {
        int M;
        scanf("%d %d",&V,&M);
        if (V==0 && M==0) {
            break;
        }
        for (int i=0; i<V; ++i) {
            G[i].clear();
        }
        for (int i=0; i<M; ++i) {
            int f,t,d,c;
            scanf("%d %d %d %d",&f,&t,&d,&c);
            --f,--t;
            G[f].push_back(edge(f,t,d,c));
            G[t].push_back(edge(t,f,d,c));
        }
        solve();
    }
    return 0;
}