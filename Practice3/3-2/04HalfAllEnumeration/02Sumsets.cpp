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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 1005

int N;
int S[MAX_N];

struct P {
  int v,i,j;
    P(){}
    P(int v,int i,int j) : v(v) , i(i) , j(j) {}
    bool operator < (const P &p) const {
        return v < p.v;
    }
    bool operator > (const P &p) const {
        return v > p.v;
    }
};

bool
init()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&S[i]);
    }
    return N>0;
}

void
solve()
{
    vector<P> a,b;
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            a.push_back(P(S[i]+S[j],i,j));
        }
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (i!=j) {
                b.push_back(P(S[i]-S[j],i,j));
            }
        }
    }

    sort(a.begin(), a.end(),greater<P>());
    sort(b.begin(), b.end());
    long long ans = -1e12;
    for (int i=0; i<a.size(); ++i) {
        vector<P>::iterator lb = lower_bound(b.begin(), b.end(), a[i]);
        vector<P>::iterator ub = upper_bound(b.begin(), b.end(), a[i]);
        for (; lb!=ub; ++lb) {
            if (lb->i != a[i].i && lb->i != a[i].j &&
                    lb->j != a[i].i && lb->j != a[i].j) {
                ans = max( ans , (long long)a[i].v+S[lb->j] );
            }
        }
    }
    if (ans == -1e12) {
        puts("no solution");
    }
    else {
        printf("%lld\n",ans);
    }
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}