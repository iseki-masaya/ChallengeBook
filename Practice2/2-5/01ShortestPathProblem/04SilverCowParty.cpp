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

#define MAX_V 1005

struct edge {
  int from,to,cost;
    edge(){}
    edge(int f,int t,int c) : from(f) , to(t) , cost(c) {}
};
typedef pair<int, int> P; //first:shortest distance second:v

vector<edge> G_forward[MAX_V];
int d_forward[MAX_V];
vector<edge> G_opposite[MAX_V];
int d_opposite[MAX_V];
int V;

void
shortest_path(int s,vector<edge> G[MAX_V],int d[MAX_V])
{
    fill(d, d+V, INF);
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    d[s] = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();

        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }

        for (int u=0; u<G[v].size(); ++u) {
            edge e = G[v][u];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

void
solve(int s)
{
    shortest_path(s,G_forward,d_forward);
    shortest_path(s,G_opposite,d_opposite);
    int ans = 0;
    for (int i=0; i<V; ++i) {
        ans = max(ans,d_forward[i]+d_opposite[i]);
    }
    printf("%d\n",ans);
}

int
main()
{
    int M,X;
    scanf("%d %d %d",&V,&M,&X);
    --X;
    for (int i=0; i<M; ++i) {
        int f,t,c;
        scanf("%d %d %d",&f,&t,&c);
        --f,--t;
        G_forward[f].push_back(edge(f,t,c));
        G_opposite[t].push_back(edge(t,f,c)); //逆向きに張ることで単一始点問題へと変更する
    }
    solve(X);
}