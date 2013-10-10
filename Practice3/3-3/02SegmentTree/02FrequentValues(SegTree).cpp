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

#define MAX_N 100005

int A[MAX_N];

struct node {
  int mx,l,r;
    node() {}
    node(int mx,int l,int r) : mx(mx), l(l), r(r) {}
};

class SegTree {
public:
    int mxs[4*MAX_N-1],ls[4*MAX_N-1],rs[4*MAX_N-1];
    int n,N;

  void
    init(int k,int l,int r)
    {
        if (r - l == 1) {
            mxs[k] = ls[k] = rs[k] = l<n;
            return;
        }
        int mid = (r+l)/2;
        int chl = 2*k+1;
        int chr = 2*k+2;

        init(chl, l, mid);
        init(chr, mid, r);
        mxs[k] = max(mxs[chl], mxs[chr]);
        ls[k] = ls[chl];
        rs[k] = rs[chr];

        if (mid < n && A[mid-1] == A[mid]) {
            mxs[k] = max(mxs[k], rs[chl]+ls[chr]);
            if (A[l] == A[mid]) {
                ls[k] += ls[chr];
            }
            if (A[mid-1] == A[r-1]) {
                rs[k] += rs[chl];
            }
        }
    }

    node
    query(int a,int b,int k,int l,int r)
    {
        if (a <= l && r <= b) {
            return node(mxs[k], ls[k], rs[k]);
        }
        if (b <= l || r <= a) {
            return node(0, -INF, -INF);
        }
        int mid = (r+l)/2;
        node chl , chr;
        chl = query(a, b, 2*k+1, l, mid);
        chr = query(a, b, 2*k+2, mid, r);

        int tmx = max(chl.mx,chr.mx);
        int tl  = chl.l;
        int tr  = chr.r;
        if (mid < n && A[mid-1] == A[mid]) {
            int conn = chl.r + chr.l;
            tmx = max(conn, tmx);
            if (A[l] == A[mid]) {
                tl = max(conn,tl);
            }
            if (A[mid-1] == A[r-1]) {
                tr = max(conn,tr);
            }
        }
        return node(tmx, tl, tr);
    }
};

int Q;
SegTree seg;

bool
init()
{
    scanf("%d",&seg.n);
    if (seg.n == 0) {
        return false;
    }
    scanf("%d",&Q);
    for (int i=0; i<seg.n; ++i) {
        scanf("%d",&A[i]);
    }

    seg.N = 1;
    while (seg.N < seg.n) {
        seg.N *= 2;
    }
    seg.init(0, 0, seg.N);
    return true;
}

void
solve(int a,int b)
{
    node ans = seg.query(a, b, 0, 0, seg.N);
    printf("%d\n",ans.mx);
}

int
main()
{
    while (init()) {
        for (int i=0; i<Q; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            solve(a-1,b);
        }
    }
}