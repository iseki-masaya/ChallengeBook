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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 50005

struct edge {
  int cost,from,to;
    edge(int f,int t,int c) : cost(c), from(f), to(t) {}
};

int
bellman_ford(vector<edge> &es)
{
    vector<int> d(MAX_N+1,0);

    for (int i=0; i<MAX_N+1; ++i) {
        bool update = false;
        for (int j=0; j<es.size(); ++j) {
            edge &e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) {
            return d[0];
        }
    }
    return INF;
}

void
solve(vector<int> &a,vector<int> &b,vector<int> &c)
{
    vector<edge> es;
    for (int i=0; i<MAX_N; ++i) {
        es.push_back(edge(i,i+1,1));
    }
    for (int i=0; i<MAX_N; ++i) {
        es.push_back(edge(i+1,i,0));
    }
    for (int i=0; i<a.size(); ++i) {
        es.push_back(edge(b[i],a[i]-1,-c[i]));
    }
    printf("%d\n",-bellman_ford(es));
}

int
main()
{
    int N;
    scanf("%d",&N);
    vector<int> a(N),b(N),c(N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
    solve(a,b,c);
    return 0;
}