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
#include <numeric>

using namespace std;

#define MAX_N 5005
typedef pair<int , int> P;

int N;
vector<P> dp;

bool
comp(const P &lhs,const P &rhs)
{
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    return lhs.first < rhs.first;
}

void
solve()
{
    sort(dp.begin(), dp.end(), comp);
    multiset<int> ms;
    multiset<int>::iterator it;
    ms.insert(0);
    for (int i=0; i<N; ++i) {
        int t = dp[i].second;

        it = ms.upper_bound(t);
        if (it != ms.begin()) {
            ms.erase(--it);
        }
        ms.insert(t);
    }

    printf("%lu\n",ms.size());
}

int
main()
{
    int T;
    scanf("%d",&T);
    for (int num=0; num<T; ++num) {
        dp.clear();
        int l,w;
        scanf("%d",&N);
        for (int i=0; i<N; ++i) {
            scanf("%d %d",&l,&w);
            dp.push_back(P(l,w));
        }
        solve();
    }
}
