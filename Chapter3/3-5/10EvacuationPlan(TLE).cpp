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

#define MAX_V 500
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

#define MAX_N 100
#define MAX_M 100

int N,M;
int X[MAX_N],Y[MAX_N],B[MAX_N];
int P[MAX_M],Q[MAX_M],C[MAX_M];
int E[MAX_N][MAX_M];

void
solve()
{
    int s = N + M, t = s + 1;
    V = t + 1;
    int cost = 0;
    int F = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            int c = abs(X[i]-P[j]) + abs(Y[i]-Q[j]) + 1;
            add_edge(i, N+j, INF, c);
            cost += E[i][j]*c;
        }
    }
    for (int i=0; i<N; ++i) {
        add_edge(s, i, B[i], 0);
        F += B[i];
    }
    for (int i=0; i<M; ++i) {
        add_edge(N+i, t, C[i], 0);
    }

    if (min_cost_flow(s, t, F) < cost) {
        printf("SUBOPTIMAL\n");
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                printf("%d%c",G[N+j][i].cap,j+1==M?'\n':' ');
            }
        }
    }
    else {
        printf("OPTIMAL\n");
    }
}

int
main()
{
    scanf("%d %d",&N,&M);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d",&X[i],&Y[i],&B[i]);
    }
    for (int i=0; i<M; ++i) {
        scanf("%d %d %d",&P[i],&Q[i],&C[i]);
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            scanf("%d",&E[i][j]);
        }
    }
    solve();
}