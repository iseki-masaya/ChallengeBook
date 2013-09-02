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

const long long int INF = 1e18;
#define MAX_N 100005

typedef pair<double, double> P;

int N;
vector<P> item;

bool
comp(const P &lhs,const P &rhs)
{
    return (lhs.second/lhs.first) < (rhs.second/rhs.first);
}

void
solve()
{
    sort(item.begin(), item.end(), comp);

    int sum = 0;
    for (int i=0; i<N; ++i) {
        sum += item[i].first;
    }

    long long res = 0;
    for (int i=0; i<N; ++i) {
        sum -= item[i].first;
        res += 2*item[i].second*sum;
    }
    printf("%lld\n",res);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        double t,d;
        scanf("%lf %lf",&t,&d);
        item.push_back(P(d,t));
    }
    solve();
    return 0;
}
