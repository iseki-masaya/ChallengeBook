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

int par[2*MAX_N];
int rnk[2*MAX_N];

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
    else {
        return par[x] = find(par[x]);
    }
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
        if (rnk[x]==rnk[y]) {
            rnk[y]++;
        }
    }
}

bool
same(int x,int y)
{
    return find(x) == find(y);
}

int N,M;
typedef pair<int, int> P;
typedef pair<char, P> C;
vector<C> cvec;

void
solve()
{
    init(2*N+1);
    for (int i=0; i<M; ++i) {
        int a = cvec[i].second.first;
        int b = cvec[i].second.second;
        if (cvec[i].first=='D') {
            unite(a, b+N);
            unite(a+N, b);
        }
        else {
            if (same(a, b)) {
                puts("In the same gang.");
            }
            else if (same(a, b+N)) {
                puts("In different gangs.");
            }
            else {
                puts("Not sure yet.");
            }
        }
    }
}

int
main()
{
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; ++i) {
        cvec.clear();
        scanf("%d %d",&N,&M);
        for (int j=0; j<M; ++j) {
            char s[8];
            int a,b;
            scanf("%s %d %d",s,&a,&b);
            cvec.push_back(C(s[0],P(--a,--b)));
        }
        solve();
    }
}