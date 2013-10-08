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

#define MAX_N 1005

struct BinaryIndexedTree {
  long long bit[MAX_N][MAX_N];

    void
    init()
    {
        memset(bit, 0, sizeof(bit));
    }

    long long
    sum(int x,int y)
    {
        long long s = 0;
        for (int ty = y ; ty > 0 ; ty -= (ty&-ty) ) {
            for (int tx = x ; tx > 0 ; tx -= (tx&-tx) ) {
                s += bit[ty][tx];
            }
        }
        return s;
    }

    void
    add(int x,int y,int v)
    {
        for (int ty = y ; ty <= MAX_N ; ty += (ty&-ty) ) {
            for (int tx = x ; tx <= MAX_N ; tx += (tx&-tx) ) {
                bit[ty][tx] += v;
            }
        }
    }
};

BinaryIndexedTree bxy,bx,by,b;

long long
sum(int x,int y)
{
    return bxy.sum(x,y)*x*y + bx.sum(x, y)*x + by.sum(x, y)*y + b.sum(x, y);
}

long long
sum(int x1,int y1,int x2,int y2)
{
    return sum(x1, y1) + sum(x2, y2) - sum(x1, y2) - sum(x2, y1);
}

void
add(int x1,int y1,int x2,int y2,int v)
{
    bxy.add(x1, y1, v);
    bxy.add(x1, y2, -v);
    bxy.add(x2, y1, -v);
    bxy.add(x2, y2, v);

    bx.add(x1, y1, v * (y1-1) );
    bx.add(x1, y2, -v * y2 );
    bx.add(x2, y1, -v * (y1-1) );
    bx.add(x2, y2, v * y2);

    by.add(x1, y1, v * (x1-1) );
    by.add(x1, y2, -v * (x1-1) );
    by.add(x2, y1, -v * x2);
    by.add(x2, y2, v * x2);

    b.add(x1, y1, v * (x1-1) * (y1-1) );
    b.add(x1, y2, -v * (x1-1) * y2);
    b.add(x2, y1, -v * x2 * (y1-1) );
    b.add(x2, y2, v * x2 * y2);
}

void
init()
{
    bxy.init();
    by.init();
    bx.init();
    b.init();
}

void
solve()
{
    int N,T;
    scanf("%d %d",&N,&T);
    for (int i=0; i<T; ++i) {
        char op;
        scanf("%*c%c%*c",&op);
        if (op == 'Q') {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",(int)(sum(x-1, y-1,x,y))&1);
        }
        else {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            add(x1, y1, x2, y2, 1);
        }
    }
}

int
main()
{
    int X;
    scanf("%d",&X);
    for (int i=0; i<X; ++i) {
        init();
        solve();
        if (i < X-1) {
            puts("");
        }
    }
    return 0;
}