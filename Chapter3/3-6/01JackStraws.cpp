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
on_seg(P p1, P p2,P q)
{
    return (p1-q).det(p2-q)==0 && (p1-q).dot(p2-q)<=0;
}

P
intersection(P p1,P p2,P q1,P q2)
{
    return p1 + (p2-p1)*( (q2-q1).det(q1-p1) / (q2-q1).det(p2-p1) );
}

#define MAX_N 20
#define MAX_M 10050

int n;
P p[MAX_N] , q[MAX_N];
int m;
int a[MAX_M] , b[MAX_M];

bool g[MAX_N][MAX_N];

void
solve()
{
    for (int i=0; i<n; ++i) {
        g[i][i] = true;
        for (int j=0; j<i; ++j) {
            if ((p[i]-q[i]).det(p[j]-q[j]) == 0) {
                g[i][j] = g[j][i] =
                        on_seg(p[i], q[i], p[j])
                ||  on_seg(p[i], q[i], q[j])
                ||  on_seg(p[j], q[j], p[i])
                ||  on_seg(p[j], q[j], q[i]);
            }
            else {
                P r = intersection(p[i], q[i], p[j], q[j]);
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
            }
        }
    }

    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for (int i=0; i<m; ++i) {
        puts(g[a[i]-1][b[i]-1] ? "CONNECTED" : "NOT CONNECTED");
    }
}

int
main()
{
    while (true) {
        memset(g, false, sizeof(g));
        scanf("%d",&n);
        if (n == 0) return 0;
        for (int i=0; i<n; ++i) {
            scanf("%lf %lf %lf %lf",&(p[i].x),&(p[i].y),&(q[i].x),&(q[i].y));
        }
        int i = 0;
        while (true) {
            scanf("%d %d",&a[i],&b[i++]);
            if (a[i-1]==0 && b[i-1]==0) break;
        }
        m = i-1;
        solve();
    }
}