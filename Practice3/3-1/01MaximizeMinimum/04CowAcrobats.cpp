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

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

typedef pair<int, int> P;
vector<P> vec;

long long S;
int N;

bool
comp(const P &lhs,const P &rhs)
{
    return lhs.first + lhs.second > rhs.first + rhs.second;
}

void
solve()
{
    sort(vec.begin(), vec.end(), comp);
    long long ans = -(1LL<<32);
    for (int i=0; i<vec.size(); ++i) {
        S -= vec[i].first;
        ans = max( ans , S - vec[i].second );
    }
    printf("%lld\n",ans);
}

int
main()
{
    scanf("%d",&N);
    S = 0;
    for (int i=0; i<N; ++i) {
        int w,s;
        scanf("%d %d",&w,&s);
        vec.push_back(P(w,s));
        S += vec[i].first;
    }
    solve();
}