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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

#define MAX_N 205
#define MAX_M 205

struct edge {
  int to,cap,rev;
    edge(int t,int c,int r) : to(t),cap(c),rev(r) {}
};

vector<vector<edge> > G;
bool used[MAX_N+MAX_M];

void
add_edge(int to,int from,int cap)
{
    G[from].push_back(edge(to,cap,(int)G[to].size()));
    G[to].push_back(edge(from,0,(int)G[from].size()-1));
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
        int f = dfs(s, t, INF);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

int N,M;

bool
init()
{
    if (scanf("%d%d",&N,&M) == EOF) {
        return false;
    }
    G.clear();
    G.resize(N+M+5);
    for (int i=0; i<N; ++i) {
        int K;
        scanf("%d",&K);
        for (int k=0; k<K; ++k) {
            int v;
            scanf("%d",&v);
            --v;
            add_edge(N+v, i, 1);
        }
    }
    return true;
}

void
solve()
{
    int source = N+M , sink = source + 1;
    for (int i=0; i<N; ++i) {
        add_edge(i, source, 1);
    }
    for (int i=0; i<M; ++i) {
        add_edge(sink, i+N, 1);
    }
    printf("%d\n",max_flow(source, sink));
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}