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

#define MAX_V 55*55*55
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

#define MAX_N 55
#define MAX_M 55

int N,M;
int Z[MAX_N][MAX_M];

void
solve()
{
    int s = N + N*M, t = s+1;
    V = t + 1;
    for (int v=0; v<V; ++v) {
        G[v].clear();
    }
    for (int i=0; i<N; ++i) {
        add_edge(s, i, 1, 0);
    }
    for (int j=0; j<M; ++j) {
        for (int k=0; k<N; ++k) {
            add_edge(N+j*N+k, t, 1, 0);
            for (int i=0; i<N; ++i) {
                add_edge(i, N+j*N+k, 1, (k+1)*Z[i][j]);
            }
        }
    }

    printf("%.6f\n",(double) min_cost_flow(s, t, N)/N);
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int n=0; n<num; ++n) {
        scanf("%d %d",&N,&M);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                scanf("%d",&Z[i][j]);
            }
        }
        solve();
    }
    return 0;
}