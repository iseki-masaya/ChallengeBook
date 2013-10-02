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

#define MAX_N 1005

int N;
double A;

bool
check(double H2,double &ans)
{
    double H1 = A;
    for (int i=3; i<=N; ++i) {
        double H3 = 2*(H2+1) - H1;
        H1 = H2;
        H2 = H3;
        if (H3 < EPS) {
            return false;
        }
    }
    ans = H2;
    return true;
}

void
solve()
{
    double lb = 0 , ub = A , mid;
    double ans = 0.0;
    for (int i=0; i<100; ++i) {
        mid = (ub+lb)/2.0;
        if (check(mid,ans)) {
            ub = mid;
        }
        else {
            lb = mid;
        }
    }
    printf("%.2lf\n",ans);
}

int
main()
{
    scanf("%d %lf",&N,&A);
    solve();
}