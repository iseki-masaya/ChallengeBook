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

#define MAX_V 505
#define INF (1<<27)

struct edge {
  int to,cap,rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void
add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}

int
dfs(int v,int t,int f)
{
    if (v == t) {
        return f;
    }
    used[v] = true;
    for (int i=0; i<G[v].size(); ++i) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f,e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int
max_flow(int s,int t)
{
    int flow = 0;
    for (;;) {
        memset(used, false, sizeof(used));
        int f = dfs(s , t, INF);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

#define MAX_N 105
#define MAX_F 105
#define MAX_D 105

int N,F,D;
bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];

void
solve()
{
    int s = N*2 + F + D , t = s + 1;
    for (int i=0; i<F; ++i) {
        add_edge(s, N*2+i, 1);
    }
    for (int i=0; i<D; ++i) {
        add_edge(N*2+F+i, t, 1);
    }
    for (int i=0; i<N; ++i) {
        add_edge(i, N+i, 1);
        for (int j=0; j<F; ++j) {
            if (likeF[i][j]) {
                add_edge(N*2+j, i, 1);
            }
        }
        for (int j=0; j<D; ++j) {
            if (likeD[i][j]) {
                add_edge(N+i, N*2+F+j, 1);
            }
        }
    }

    printf("%d\n",max_flow(s, t));
}

int
main()
{
    memset(likeF, false, sizeof(likeF));
    memset(likeD, false, sizeof(likeD));
    scanf("%d %d %d",&N,&F,&D);
    for (int i=0; i<N; ++i) {
        int f,d;
        scanf("%d %d",&f,&d);
        for (int j=0; j<f; ++j) {
            int fi;
            scanf("%d",&fi);
            likeF[i][--fi] = true;
        }
        for (int j=0; j<d; ++j) {
            int di;
            scanf("%d",&di);
            likeD[i][--di] = true;
        }
    }
    solve();
}