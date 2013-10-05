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

int N;
double L,V;
double n_mx , r_mx;
typedef pair<double, string> P;
vector<P> p;

bool
init()
{
    scanf("%d",&N);
    if (N == 0) {
        return false;
    }
    scanf("%lf %lf",&L,&V);
    p.clear();
    for (int i=0; i<N; ++i) {
        char ch;
        double pos;
        string n;
        cin >> ch >> pos >> n;
        if (ch == 'n' || ch == 'N') {
            pos = - pos;
        }
        p.push_back(P(pos,n));
    }
    return true;
}

bool
comp(const P &lhs,const P &rhs)
{
    return abs(lhs.first) < abs(rhs.first);
}

void
solve()
{
    sort(p.begin(), p.end(),comp);
    double d = 0.0;
    int idx = 0;
    bool is_right = true;
    for (int i=0; i<N; ++i) {
        double t = p[i].first < 0.0 ? 0.0 : L;
        if (t - p[i].first > d + EPS) {
            d = t - p[i].first;
            idx = i;
            is_right = p[i].first > 0;
        }
    }
    double ans = d/V;

    int cnt = 0;
    int di = is_right?1:-1;
    for (int i=idx; (is_right&&i<N) || (!is_right&&i>=0); i+=di) {
        if ( (is_right && p[i].first < EPS) || (!is_right && p[i].first > EPS) ) {
            ++cnt;
        }
    }
    idx += is_right ? cnt : -cnt;
    printf("%13.2lf %s\n",(int)(ans*100)/100.0,p[idx].second.c_str());
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}