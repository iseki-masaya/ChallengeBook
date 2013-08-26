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

const int MAX_N = 1005;
const double EPS = 1e-6;

typedef pair<double, double> P;

int n,d;
vector<P> p;

int
solve()
{
    sort(p.begin(), p.end());
    int res = 1;
    double ub = p[0].first;
    for (int i=1; i<n; ++i) {
        if (p[i].second > ub && p[i].second-ub > EPS ) {
            ++res;
            ub = p[i].first;
        }
    }
    return res;
}

int
main()
{
    int num = 0;
    while (true) {
        p.clear();
        bool ng = false;
        scanf("%d %d",&n,&d);
        if (n == 0 && d == 0) {
            return 0;
        }
        for (int i=0; i<n; ++i) {
            int x,y;
            scanf("%d %d",&x,&y);
            ng |= ng | (y > d);
            double dx = sqrt((double)(d*d-y*y));
            double ub = x + dx;
            double lb = x - dx;
            p.push_back(P(ub,lb));
        }
        int ans = ng ? -1 : solve();
        printf("Case %d: %d\n",++num,ans);
    }
}