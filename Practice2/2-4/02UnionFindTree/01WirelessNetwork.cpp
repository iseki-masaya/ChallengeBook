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
#include <time.h>

#define INF (1<<30)

using namespace std;

#define MAX_N 300500
#define MAX_NODE 1050

int par[MAX_NODE];
int r[MAX_NODE];

void
init(int n)
{
    for (int i=0; i<n; ++i) {
        par[i] = i;
        r[i] = 0;
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
    if (x==y) {
        return;
    }
    if (r[x] < r[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (r[x] == r[y]) {
            r[x]++;
        }
    }
}

bool
same(int x,int y)
{
    return find(x) == find(y);
}

typedef pair<int, int> P;
typedef pair<char, P> Op;
vector<P> pos;
vector<Op> op;
int N,d;
bool isRepair[MAX_NODE];

bool
isIn(int i,int j)
{
    int sx = pos[i].first , sy = pos[i].second;
    int dx = pos[j].first , dy = pos[j].second;
    return (sx-dx)*(sx-dx) + (sy-dy)*(sy-dy) <= d*d;
}


void
solve()
{
    memset(isRepair, false, sizeof(isRepair));
    init(N+10);
    for (int i=0; i<op.size(); ++i) {
        if (op[i].first == 'O' && !isRepair[op[i].second.first]) {
            int idx = op[i].second.first;
            for (int j=0; j<N; ++j) {
                if (isRepair[j] && isIn(idx, j)) {
                    unite(idx,j);
                }
            }
            isRepair[idx] = true;
        }
        else {
            int src = op[i].second.first;
            int dst = op[i].second.second;
            if (isRepair[src] && isRepair[dst] && same(src, dst)) {
                printf("SUCCESS\n");
            }
            else {
                printf("FAIL\n");
            }
        }
    }
}

int
main()
{
    scanf("%d %d",&N,&d);
    for (int i = 0; i<N; ++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        pos.push_back(P(x,y));
    }
    char c[1];
    while (scanf("%s",c) != EOF) {
        if (c[0] == 'O') {
            int r;
            scanf("%d",&r);
            op.push_back(Op(c[0],P(--r,0)));
        }
        else {
            int src,dst;
            scanf("%d %d",&src,&dst);
            op.push_back(Op(c[0],P(--src,--dst)));
        }
    }
    solve();
}