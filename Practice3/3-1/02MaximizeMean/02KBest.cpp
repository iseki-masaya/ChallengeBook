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

#define MAX_N 100005
int N,K;
int V[MAX_N],W[MAX_N];

struct P {
  int idx;
    double val;
    P(){}
    P(const int i , const double v) : idx(i) , val(v) {}
    bool operator < (const P p) const {
        return val < p.val;
    }
    bool operator > (const P p) const {
        return val > p.val;
    }
};

bool
check(double m,vector<P> &p)
{
    for (int i=0; i<N; ++i) {
        p[i] = P(i+1,V[i] - m*W[i]);
    }
    double sum = 0.0;
    sort(p.begin(),p.end(),greater<P>());
    for (int i=0; i<K; ++i) {
        sum += p[i].val;
    }
    return sum >= 0.0;
}

void
solve()
{
    vector<P> p(N);
    double lb = 0.0 , ub = 10000001 , mid;
    for (int i=0; i<50 ; ++i) {
        mid = (lb+ub)/2.0;
        if (check(mid,p)) {
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    for (int i=0; i<K; ++i) {
        printf("%d%c",p[i].idx,i+1==K ? '\n' : ' ');
    }
}

int
main()
{
    scanf("%d %d",&N,&K);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&V[i],&W[i]);
    }
    solve();
    return 0;
}