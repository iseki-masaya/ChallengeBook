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

#define MAX_N (1<<20)

class SegTree {
public:
    int dat[2*MAX_N];
    int RMQ_N;

  void
    init(int n)
    {
        RMQ_N = 1;
        while (RMQ_N < n) {
            RMQ_N *= 2;
        }
        for (int i=0; i<2*RMQ_N-1; ++i) {
            dat[i] = -INF;
        }
    }

    void
    update(int k,int v)
    {
        k += RMQ_N - 1;
        dat[k] = v;
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = max(dat[2*k+1],dat[2*k+2]);
        }
    }

    int
    query(int a,int b,int k,int l,int r)
    {
        if (r <= a || b <= l) {
            return -INF;
        }
        if (a <= l && r <=b) {
            return dat[k];
        }
        else {
            int mid = (l+r)/2;
            int lv = query(a, b, 2*k+1, l, mid);
            int rv = query(a, b, 2*k+2, mid, r);
            return max(lv, rv);
        }
    }
};

int N,Q;
int as[MAX_N];
int xs[MAX_N];
int accum[MAX_N];
SegTree seg_tree;

bool
init()
{
    scanf("%d",&N);
    if (N == 0) {
        return false;
    }
    scanf("%d",&Q);
    for (int i=0; i<N; ++i) {
        scanf("%d",&as[i]);
    }

    int cnt=1,p=0;
    for (int i=0; i<N-1; ++i) {
        if (as[i] == as[i+1]) {
            ++cnt;
        }
        else {
            xs[p++] = cnt;
            cnt = 1;
        }
    }
    xs[p++] = cnt;
    N = p;

    accum[0] = 0;
    for (int i=0; i<N; ++i) {
        accum[i+1] = accum[i] + xs[i];
    }
    seg_tree.init(N);
    for (int i=0; i<N; ++i) {
        seg_tree.update(i, xs[i]);
    }
    return true;
}

int
solve(int from,int to)
{
    int a = int(lower_bound(accum, accum+N+1, from) - accum);
    int b = int(lower_bound(accum, accum+N+1, to) - accum) - 1;
    if (a == b+1) {
        return to-from+1;
    }
    int aa = accum[a] - from + 1;
    int bb = to - accum[b];
    int ret = max(aa,bb);
    ret = max(ret, seg_tree.query(a, b, 0, 0, seg_tree.RMQ_N));
    return ret;
}

int
main()
{
    while (init()) {
        for (int i=0; i<Q; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",solve(a,b));
        }
    }
    return 0;
}
/*
8 3
-1 -1 1 1 1 1 3 10
2 3
1 8
5 8
0
 */
