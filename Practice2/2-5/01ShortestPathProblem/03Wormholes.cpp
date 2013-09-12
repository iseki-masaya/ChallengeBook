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

#define MAX_V 505
#define MAX_E (2505*2 + 205)
#define PINF 10000

struct edge {
  int from,to,cost;
    edge() {}
    edge(int f,int t,int c) :from(f),to(t),cost(c) {}
};

edge es[MAX_E];

int d[MAX_V];
int V,E;

void
solve()
{
    memset(d, 0, sizeof(d));

    for (int i=0; i<V; ++i) {
        for (int j=0; j<E; ++j) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from]+e.cost;
                if (i == V-1) {
                    puts("YES");
                    return;
                }
            }
        }
    }
    puts("NO");
}

int
main()
{
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; ++i) {
        int M,W;
        scanf("%d %d %d",&V,&M,&W);
        E = 2*M + W;
        for (int i=0; i<M; ++i) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            --a,--b;
            es[2*i] = edge(a,b,c);
            es[2*i+1] = edge(b,a,c);
        }
        for (int i=0; i<W; ++i) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            --a,--b;
            es[2*M+i] = edge(a,b,-c);
        }
        solve();
    }
}