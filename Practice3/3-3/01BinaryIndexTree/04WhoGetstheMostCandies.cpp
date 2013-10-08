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

#define MAX_N (500005)

int F[MAX_N];
int N,K;
char names[MAX_N][11];
int vs[MAX_N];

class BIT {
    public :

  int bit[MAX_N];
    int _size;

    BIT(int s) : _size(s) {
        memset(bit, 0, sizeof(bit));
    }

    int
    sum(int i)
    {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= (i&-i);
        }
        return s;
    }

    void
    add(int i,int v)
    {
        ++i;
        while (i <= MAX_N) {
            bit[i] += v;
            i += (i&-i);
        }
    }

    int
    search_index(int id)
    {
        int lb = 0 , ub = _size;
        while (ub - lb > 1) {
            int md = (ub+lb)/2;
            if (sum(md) <= id) {
                lb = md;
            }
            else {
                ub = md;
            }
        }
        return lb;
    }

};

void calcF(int n) {
    fill(F, F + n + 1, 1);
    for (int i = 2; i <= n; ++i) if (F[i] == 1) {
        for (int j = i; j <= n; j += i) {
            int k = 0;
            for (int m = j; m % i == 0; m /= i, ++k) ;
            F[j] *= k + 1;
        }
    }
}

bool
init()
{
    int err = scanf("%d%d",&N,&K);
    if (err == EOF) {
        return false;
    }
    --K;
    for (int i=0; i<N; ++i) {
        scanf("%s %d",names[i],&vs[i]);
    }
    return true;
}

void
solve()
{
    BIT b(N);
    for (int i=0; i<N; ++i) {
        b.add(i, 1);
    }

    int max = -1 , key = -1;
    for (int i=0; i<N; ++i) {
        if (max < F[i+1]) {
            max = F[i+1];
            key = K;
        }
        b.add(K, -1);
        if (i < N-1) {
            int mod = N-i-1;
            int id = b.sum(K) + vs[K] + (vs[K]>0 ? -1 : 0);
            id = (id%mod +mod)%mod;
            K = b.search_index(id);
        }
    }
    printf("%s %d\n",names[key],max);
}

int
main()
{
    calcF(MAX_N);
    while (init()) {
        solve();
    }
    return 0;
}