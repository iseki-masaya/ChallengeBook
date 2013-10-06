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

#define MAX_N 20009
#define MAX_X 20009

long long
sum(long long bit[MAX_N],int i)
{
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i&-i;
    }
    return s;
}

long long
sum(long long bit[MAX_N],int from,int to)
{
    return sum(bit, to-1) - sum(bit, from-1);
}

void
add(long long bit[MAX_N],int i,int x)
{
    while (i <= MAX_N) {
        bit[i] += x;
        i += i&-i;
    }
}

int N;
typedef pair<int, int> P;
vector<P> ps;
long long cs[MAX_N],xs[MAX_N];

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
    sort(ps.begin(), ps.end());
    long long ans = 0;
    for (int i=0; i<ps.size(); ++i) {
        int v = ps[i].first , x = ps[i].second;
        long long c1 = sum(cs,1,x) , c2 = sum(cs,x+1,MAX_X);
        ans += v * ( (c1*x - sum(xs,1,x)) + (sum(xs,x+1,MAX_X) - c2*x) );
        add(cs, x, 1);
        add(xs, x, x);
    }
    printf("%lld\n",ans);
}

int
main()
{
    init();
    solve();
}