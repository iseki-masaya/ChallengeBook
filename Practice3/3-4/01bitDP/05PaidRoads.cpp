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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_N 11

typedef pair<int, int> P;

struct edge {
  int from,to,c;
    P cost;
    edge(int f,int t,int c,P p) : from(f), to(t), c(c), cost(p) {}
};

int N,M;
vector<edge> es;

bool
init()
{
    scanf("%d%d",&N,&M);
    for (int i=0; i<M; ++i) {
        int a,b,c,p,r;
        scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
        --a,--b,--c;
        es.push_back(edge(a, b, c, P(p,r)));
    }
    return true;
}

int
solve()
{
    int lim = (1<<N);
    int dp[1<<MAX_N][MAX_N];
    for (int i=0; i<lim; ++i) {
        fill(dp[i], dp[i]+N, INF);
    }

    dp[1][0] = 0;
    for (int n=0; n<N; ++n) {
        for (int s=1; s<lim; ++s) {
            for (int m=0; m<M; ++m) {
                edge &e = es[m];
                if ((1<<e.from) & s && dp[s][e.from] != INF) {
                    int c = (1<<e.c) & s ? e.cost.first : e.cost.second;
                    dp[s|(1<<e.to)][e.to] = min(dp[s|(1<<e.to)][e.to], dp[s][e.from] + c);
                }
            }
        }
    }

    int ans = INF;
    for (int s=0; s<lim; ++s) {
        ans = min(ans, dp[s][N-1]);
    }

    return ans;
}

int
main()
{
    init();
    int ans = solve();
    if (ans == INF) {
        puts("impossible");
    }
    else {
        printf("%d\n",ans);
    }
    return 0;
}