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

int N;
typedef pair<int, int> P;
vector<P> ps;

bool
init()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        int v,d;
        scanf("%d %d",&v,&d);
        ps.push_back(P(v,d));
    }
    return true;
}

void
solve()
{
    long long ans = 0;
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            ans += max(ps[i].first,ps[j].first)*abs(ps[i].second-ps[j].second);
        }
    }
    printf("%lld\n",ans);
}

int
main()
{
    init();
    solve();
}