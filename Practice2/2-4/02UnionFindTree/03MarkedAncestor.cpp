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

#define INF (1<<28)

using namespace std;

#define MAX_N 100005

int par[MAX_N];
int rnk[MAX_N];
bool mark[MAX_N];

void
init(int n)
{
    memset(mark, false, sizeof(mark));
    for (int i=0; i<n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int
find(int x)
{
    if (par[x] == x || mark[x]) {
        return x;
    }
    else {
        return find(par[x]);
    }
}

void
unite(int x,int y)
{
    x = find(x);
    y = find(y);
    if (rnk[x] > rnk[y]) {
        par[y] = x;
    }
    else {
        par[x] = y;
        if (rnk[x] == rnk[y]) {
            rnk[x]++;
        }
    }
}

bool
same(int x,int y)
{
    return find(x) == find(y);
}

int N,T;

int
main()
{
    for (;;) {
        scanf("%d %d",&N,&T);
        if (N==0 && T==0) {
            break;
        }
        mark[0] = true;
        init(N+1);
        for (int i=1; i<N; ++i) {
            int n;
            scanf("%d",&n);
            par[i] = --n;
        }
        long long ans = 0;
        for (int i=0; i<T; ++i) {
            char c[8];
            int v;
            scanf("%s %d",c,&v);
            --v;
            if (c[0] == 'Q') {
                ans += find(v)+1;
            }
            else {
                mark[v] = true;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}