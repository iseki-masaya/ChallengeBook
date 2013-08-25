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

using namespace std;

#define MAX_V 550
#define INF (1<<26)

struct edge {
  int to,cap,cost,rev;
};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void
add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge{to,cap,cost,(int)G[to].size()}));
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}

int
min_cost_flow(int s,int t,int f)
{
    int res = 0;
    while (f > 0) {
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int v = 0 ; v < V; ++v) {
                if (dist[v] == INF) {
                    continue;
                }
                for (int i=0; i<G[v].size(); ++i) {
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }

        if (dist[t] == INF) {
            return -1;
        }

        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d , G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d*dist[t];
        for (int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

#define MAX_N 205

int N,K;
int a[MAX_N],b[MAX_N],w[MAX_N];

void
solve()
{
    vector<int> x;
    for (int i=0; i<N; ++i) {
        x.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()),x.end());

    int m = (int)x.size();
    int s = m , t = s + 1;
    V = t + 1;

    for (int v=0; v<V; ++v) {
        G[v].clear();
    }

    int res = 0;
    add_edge(s, 0, K, 0);
    add_edge(m-1, t, K, 0);
    for (int i=0; i+1<m; ++i) {
        add_edge(i, i+1, INF, 0);
    }
    for (int i=0; i<N; ++i) {
        int u = (int)distance(x.begin(),find(x.begin(), x.end(), a[i]));
        int v = (int)distance(x.begin(),find(x.begin(), x.end(), b[i]));
        add_edge(v, u, 1, w[i]);
        add_edge(s, v, 1, 0);
        add_edge(u, t, 1, 0);
        res -= w[i];
    }

    res += min_cost_flow(s, t, K+N);
    printf("%d\n",-res);
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int n=0; n<num; ++n) {
        scanf("%d %d",&N,&K);
        for (int i=0; i<N; ++i) {
            scanf("%d %d %d",&a[i],&b[i],&w[i]);
        }
        solve();
    }
    return 0;
}