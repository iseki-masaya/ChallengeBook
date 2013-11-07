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

const int MAX_N = 505;

struct edge {
  int from,to,cap;
    edge(int f,int t,int c) : from(f),to(t),cap(c) {}
};

vector<vector<edge> > G;
int N,M;
bool used[MAX_N];

int
minimum_cut()
{
    vector<vector<int> > h(N,vector<int>(N,0));
    for (int v=0; v<N; ++v) {
        for (int i=0; i<G[v].size(); ++i) {
            edge &e = G[v][i];
            h[e.from][e.to] += e.cap;
        }
    }
    vector<int> V(N);
    for (int i=0; i<N; ++i) {
        V[i] = i;
    }

    int cut = INF;
    for (int m=N; m > 1; --m) {
        vector<int> ws(m,0);
        int u=0,v=0;
        int w;
        for (int k=0; k<m; ++k) {
            u = v;
            v = (int)distance(ws.begin(), max_element(ws.begin(), ws.end()));
            w = ws[v];
            ws[v] = -1;
            for (int i=0; i<m; ++i) {
                if (ws[i] >= 0) {
                    ws[i] += h[V[v]][V[i]];
                }
            }
        }
        for (int i=0; i<m; ++i) {
            h[V[i]][V[u]] += h[V[i]][V[v]];
            h[V[u]][V[i]] += h[V[v]][V[i]];
        }
        V.erase(V.begin()+v);
        cut = min(cut,w);
    }
    return cut;
}

bool
init()
{
    G.clear();
    if (scanf("%d%d",&N,&M) == EOF) {
        return false;
    }
    G.resize(N+2);
    for (int i=0; i<M; ++i) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(edge(a,b,c));
        G[b].push_back(edge(b,a,c));
    }
    return true;
}

void
solve()
{
    printf("%d\n",minimum_cut());
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}