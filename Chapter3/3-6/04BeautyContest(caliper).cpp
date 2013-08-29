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

const double EPS = 1e-10;
#define MAX_N 50005

double
add(double a, double b)
{
    if (abs(a+b) < EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

struct P {
  double x,y;
    P() {}
    P(double x,double y) : x(x), y(y)
    { }

    P
    operator + (P p)
    {
        return P(add(x, p.x),add(y, p.y));
    }

    P
    operator - (P p)
    {
        return P(add(x, -p.x),add(y, -p.y));
    }

    P
    operator * (double d)
    {
        return P(x*d,y*d);
    }

    double
    dot(P p)
    {
        return add(x*p.x, y*p.y);
    }

    double
    det(P p )
    {
        return add(x*p.y, -y*p.x);
    }
};

bool
cmp_x(const P &lhs,const P &rhs)
{
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

vector<P>
convex_hull(P *ps,int n)
{
    sort(ps, ps+n, cmp_x);
    int k=0;
    vector<P> qs(n*2);
    for (int i=0; i<n; ++i) {
        while (k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) --k;
        qs[k++] = ps[i];
    }
    for (int i=n-2 , t=k; i>=0; --i) {
        while (k>t && (qs[k-1] - qs[k-2]).det(ps[i]-qs[k-1]) <=0) --k;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

double
dist(P p,P q)
{
    return (p-q).dot(p-q);
}

int N;
P ps[MAX_N];

void
solve()
{
    vector<P> qs = convex_hull(ps, N);
    int n = (int)qs.size();
    if (n==2) {
        printf("%.0f\n",dist(qs[0],qs[1]));
        return;
    }
    int i=0,j=0;
    for (int k=0; k<n; ++k) {
        if (!cmp_x(qs[i], qs[k])) i=k;
        if (cmp_x(qs[j], qs[k])) j=k;
    }
    double res = 0;
    int si = i , sj = j;
    while (i != sj || j != si) {
        res = max(res,dist(qs[i],qs[j]));
        if ((qs[(i+1)%n]-qs[i]).det(qs[(j+1)%n]-qs[j]) < 0) {
            i = (i+1)%n;
        }
        else {
            j = (j+1)%n;
        }
    }
    printf("%.0f\n",res);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%lf %lf",&(ps[i].x),&(ps[i].y));
    }
    solve();
}