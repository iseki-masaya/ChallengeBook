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

#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define MAX_N 40

int N;
long long S[MAX_N];
typedef pair<long long, int> P;

long long
_abs(long long n)
{
    return n > 0 ? n : -n;
}

bool
abs_comp(const P &lhs,const P &rhs)
{
    if (_abs(lhs.first) == _abs(rhs.first)) {
        return lhs.second < rhs.second;
    }
    return _abs(lhs.first) < _abs(rhs.first);
}

bool
init()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%lld",&S[i]);
    }
    return N>0;
}

void
solve()
{
    if (N==1) {
        printf("%lld 1\n",_abs(S[0]));
        return;
    }

    int half = N - N/2;
    vector<P> sum1,sum2;
    //enum
    for (int p = 1; p>=0; --p) {
        int lim = p ? (1<<half) : ( 1<<(N-half) );
        int bound = p ? half : N-half;
        int offset = p ? 0 : half;
        vector<P> &c = p ? sum1 : sum2;

        for (int i=1; i<lim; ++i) {
            long long t = 0;
            int cnt = 0;
            for (int j=0; j<bound; ++j) {
                if ((i>>j)&1) {
                    t += S[j+offset];
                    ++cnt;
                }
            }
            c.push_back(P(t,cnt));
        }
    }

    //binary search
    sort(sum1.begin(), sum1.end(),abs_comp);
    sort(sum2.begin(), sum2.end(),abs_comp);
    long long mn = 1e16;
    int ct = 1;
    if (abs_comp(sum1[0], sum2[0])) {
        mn = _abs(sum1[0].first) , ct = sum1[0].second;
    }
    else {
        mn = _abs(sum2[0].first) , ct = sum2[0].second;
    }

    sort(sum1.begin(), sum1.end());
    for (int i=1; i<(int)sum1.size(); ++i) {
        if (sum1[i].first == sum1[i-1].first) {
            sum1[i].second = sum1[i-1].second;
        }
    }
    sum1.erase(unique(sum1.begin(), sum1.end()),sum1.end());

    for (int i=0; i<sum2.size(); ++i) {
        vector<P>::iterator it = lower_bound(sum1.begin(), sum1.end(), P(-sum2[i].first,0));
        for (int k=-1; k<=0; ++k) {
            if ((it+k) < sum1.begin() || sum1.end() < (it+k)) {
                continue;
            }
            P p = *(it+k);
            long long sum = _abs(p.first + sum2[i].first);
            if (sum <= mn) {
                int t = p.second + sum2[i].second;
                ct = ((mn == sum) ? min(ct,t) : t);
                mn = sum;
            }
        }
    }

    printf("%lld %d\n",mn,ct);
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}
