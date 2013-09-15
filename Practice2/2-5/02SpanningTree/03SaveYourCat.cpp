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
#define EPS 1e-6

using namespace std;

#define MAX_V 10005
struct edge {
    int u,v;
    double cost;
    edge(){}
    edge(int u,int v,double c) : u(u),v(v),cost(c)
    {}
};
int V;
vector<edge> es;
double sum = 0;

int par[MAX_V];
int rnk[MAX_V];

void
init(int n)
{
    for (int i=0; i<n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int
find(int x)
{
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void
unite(int x,int y)
{
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }
    if (rnk[x] > rnk[y]) {
        par[y] = x;
    }
    else {
        par[x] = y;
        if (rnk[x] == rnk[y]) {
            rnk[y]++;
        }
    }
}

bool
same(int x,int y)
{
    return find(x) == find(y);
}

double
calcDist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool
comp(const edge &lhs,const edge &rhs)
{
    return lhs.cost > rhs.cost;
}

void
solve()
{
    init(V);
    sort(es.begin(), es.end(),comp);

    double res = 0;
    for (int i=0; i<es.size(); ++i) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    printf("%f\n",sum-res);
}

int
main()
{
    int E;
    int x[MAX_V],y[MAX_V];
    scanf("%d %d",&V,&E);
    es.reserve(E);
    for (int i=0; i<V; ++i) {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i=0; i<E; ++i) {
        int a,b;
        double dist;
        scanf("%d %d",&a,&b);
        --a,--b;
        dist = calcDist(x[a], y[a], x[b], y[b]);
        es.push_back(edge(a,b,dist));
        sum += dist;
    }
    solve();
}