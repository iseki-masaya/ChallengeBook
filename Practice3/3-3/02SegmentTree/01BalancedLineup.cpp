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

#define MAX_N (1<<17)

class Seg {
public:
  int _size , min_dat[2*MAX_N-1] , max_dat[2*MAX_N-1];

    void
    init(int n)
    {
        _size = 1;
        while (_size < n) {
            _size *= 2;
        }
        for (int i=0; i<2*_size-1;++i) {
            min_dat[i] = INF;
            max_dat[i] = -1;
        }
    }

    void
    update(int k,int v)
    {
        k += _size - 1;
        min_dat[k] = v;
        max_dat[k] = v;
        while (k > 0) {
            k = (k-1)/2;
            min_dat[k] = min(min_dat[k*2+1],min_dat[k*2+2]);
            max_dat[k] = max(max_dat[k*2+1],max_dat[k*2+2]);
        }
    }

    //[a,b)
    int
    min_query(int a,int b,int k,int l,int r)
    {
        if (b <= l || r <= a) {
            return INF;
        }
        if (a <= l && r <= b) {
            return min_dat[k];
        }
        else {
            int vl = min_query(a, b, 2*k+1, l, (r+l)/2);
            int vr = min_query(a, b, 2*k+2, (r+l)/2, r);
            return min(vl, vr);
        }
    }

    //[a,b)
    int
    max_query(int a,int b,int k,int l,int r)
    {
        if (b <= l || r <= a) {
            return -1;
        }
        if (a <= l && r <= b) {
            return max_dat[k];
        }
        else {
            int vl = max_query(a, b, 2*k+1, l, (r+l)/2);
            int vr = max_query(a, b, 2*k+2, (r+l)/2, r);
            return max(vl, vr);
        }
    }
};

int N,Q;
Seg seg_tree;

bool
init()
{
    scanf("%d%d",&N,&Q);
    seg_tree.init(N);
    for (int i=0; i<N; ++i) {
        int v;
        scanf("%d",&v);
        seg_tree.update(i, v);
    }
    return true;
}

int
main()
{
    init();
    N = seg_tree._size;
    for (int i=0; i<Q; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;
        printf("%d\n", seg_tree.max_query(a,b,0,0,N) - seg_tree.min_query(a,b,0,0,N) );
    }
}