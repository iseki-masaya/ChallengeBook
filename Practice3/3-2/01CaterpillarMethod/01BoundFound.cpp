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

#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define MAX_N 100005

typedef pair<int, int> P;

int N,k;
vector<P> accum;

bool
init()
{
    scanf("%d %d",&N,&k);
    accum.clear();
    accum.resize(N+1);
    accum[0] = P(0,0);
    for (int i=1; i<N+1; ++i) {
        int a;
        scanf("%d",&a);
        accum[i] = P( accum[i-1].first + a , i );
    }
    sort(accum.begin(), accum.end());

    return N > 0;
}

int
update(int l,int r,int t,int &ans,int &lb,int &ub)
{
    if (l >= r) {
        return -INF;
    }

    int v = accum[r].first - accum[l].first;

    if (abs(t-v) < abs(t-ans)) {
        ans = v;
        int r_idx = accum[r].second , l_idx = accum[l].second;
        lb = min(r_idx,l_idx);
        ub = max(r_idx,l_idx);
    }

    return v;
}

void
solve()
{
    int t;
    scanf("%d",&t);
    int ans = -INF , lb = -1 , ub = -1;
    for (int l=0 , r=0 , sum = -INF;;) {
        while (r < N && sum < t) {
            sum = update(l, ++r, t, ans,lb,ub);
        }
        if (sum < t) {
            break;
        }
        sum = update(++l,r,t,ans,lb,ub);
    }

    printf("%d %d %d\n",ans,lb+1,ub);
}

int
main()
{
    while (init()) {
        for (int i=0; i<k; ++i) {
            solve();
        }
    }
    return 0;
}
