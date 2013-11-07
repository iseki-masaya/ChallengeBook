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
const int MOD = 10007;

using namespace std;

#define MAX_N 5050

struct edge {
  int to,rev;
    long long cap;
    edge(int to,long long cap,int rev) : to(to),cap(cap),rev(rev) {}
};

typedef pair<int, long long> P;
vector<edge> G[MAX_N];
bool used[MAX_N];
int level[MAX_N];
int iter[MAX_N];

void
add_edge(int from,int to,long long cap)
{
    G[from].push_back(edge(to,cap,(int)G[to].size()));
    G[to].push_back(edge(from,0,(int)G[from].size()-1));
}

void
bfs_dinic(int s)
{
    memset(level, -1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i=0; i<G[v].size(); ++i) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

long long
dfs_dinic(int v,int t,long long f)
{
    if (v == t) {
        return f;
    }
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            long long d = dfs_dinic(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

long long
max_flow_dinic(int s,int t)
{
    long long flow = 0;
    for (;;) {
        bfs_dinic(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        long long f;
        while ((f = dfs_dinic(s, t, LINF)) > 0) {
            flow += f;
        }
    }
}

int V[MAX_N];
int N,M;

bool
init()
{
    scanf("%d%d",&N,&M);
    for (int i=0; i<N; ++i) {
        scanf("%d",&V[i]);
    }
    for (int i=0; i<M; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a , --b;
        add_edge(a, b, LINF);
    }
    return true;
}

P
count(int s)
{
    memset(used, false, sizeof(used));
    queue<int> que;
    que.push(s);

    P res = P(0,0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        used[v] = true;
        for (int i=0; i<G[v].size(); ++i) {
            edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                que.push(e.to);
                res.first++;
                res.second += V[e.to];
                used[e.to] = true;
            }
        }
    }
    return res;
}

void
solve()
{
    int source = N, sink = N+1;
    for (int i=0; i<N; ++i) {
        if (V[i] > 0) {
            add_edge(source, i, V[i]);
        }
        else if (V[i] < 0){
            add_edge(i, sink, -V[i]);
        }
    }
    max_flow_dinic(source, sink);
    P p = count(source);
    printf("%d %lld\n",p.first,p.second);
}

int
main()
{
    init();
    solve();
    return 0;
}