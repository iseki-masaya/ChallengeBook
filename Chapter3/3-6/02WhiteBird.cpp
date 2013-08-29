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

#define MAX_N 55
const double EPS = 1e-6;

const double g = 9.8;

int N,V,X,Y;
int L[MAX_N],B[MAX_N],R[MAX_N],T[MAX_N];

double
calc(double vy,double t)
{
    return vy*t - g*t*t/2;
}

int
cmp(double lb,double ub,double a)
{
    return a<lb+EPS ? -1 : a > ub-EPS ? 1 : 0;
}

bool
check(double qx,double qy)
{
    double a=g*g/4 , b=g*qy-V*V , c=qx*qx+qy*qy;
    double D = b*b-4*a*c;
    if (D < 0 && D > -EPS) D = 0;
    if (D < 0) return false;
    for (int d=-1; d<=1; d+=2) {
        double t2 = (-b+d*sqrt(D))/(2*a);
        if (t2 <= 0) continue;
        double t = sqrt(t2);
        double vx = qx / t , vy = (qy + g*t*t/2) / t;

        double yt = calc(vy, X/vx);
        if (yt < Y-EPS) continue;

        bool ok = true;
        for (int i=0; i<N; ++i) {
            if (L[i] >= X) continue;
            if (R[i] == X && Y <= T[i] && B[i] <= yt) ok = false;

            int yL = cmp(B[i], T[i], calc(vy, L[i] / vx));
            int yR = cmp(B[i], T[i], calc(vy, R[i] / vx));
            int xH = cmp(L[i], R[i], vx*(vy/g));
            int yH = cmp(B[i], T[i], calc(vy, vy/g));
            if (xH==0 && yH >= 0 && yL < 0) ok = false;
            if (yL*yR <= 0) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

void
solve()
{
    for (int i=0; i<N; ++i) {
        R[i] = min(R[i],X);
    }
    bool ok = check(X, Y);
    for (int i=0; i<N; ++i) {
        ok |= check(L[i], T[i]);
        ok |= check(R[i], T[i]);
    }
    puts(ok ? "Yes" : "No");
}

int
main()
{
    scanf("%d %d %d %d",&N,&V,&X,&Y);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d %d",&L[i],&B[i],&R[i],&T[i]);
    }
    solve();
}