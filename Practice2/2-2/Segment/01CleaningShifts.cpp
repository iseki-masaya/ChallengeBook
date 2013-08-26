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

using namespace std;

#define MAX_N 25005
#define INF (1<<28)

int N,T;

typedef pair<int, int> P;
P p[MAX_N];

bool
comp(const P &lhs,const P &rhs)
{
    return lhs.first < rhs.first;
}

int
get_max(int l,int r)
{
    int mx = -1;
    for (int i=0; p[i].first<=r; ++i) {
        if (p[i].first > r) break;
        if (l <= p[i].first && p[i].first <= r) {
            mx = max(mx,p[i].second);
        }
        if (N==i+1 && mx < T)
            return -1;
    }
    return mx;
}

void
solve()
{
    sort(p, p+N , comp);
    if (p[0].first != 1) {
        printf("-1\n");
        return;
    }

    int lb = 0 , ub = 0;
    int res = 0;
    while (ub < T) {
        int mx = get_max(lb, ub+1);
        if (mx==-1) {
            printf("-1\n");
            return;
        }
        lb = ub;
        ub = mx;
        ++res;
    }

    printf("%d\n",res);
}

int
main()
{
    scanf("%d %d",&N,&T);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&(p[i].first),&(p[i].second));
    }
    p[N].first = INF , p[N++].second = INF;
    solve();
    return 0;
}