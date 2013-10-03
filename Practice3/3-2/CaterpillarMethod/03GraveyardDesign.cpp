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

typedef pair<unsigned long long, unsigned long long> P;

unsigned long long N;

void
solve()
{
    unsigned long long sum = 0;
    int ans_num = 0;
    vector<P> ans;
    for (unsigned long long l=0,r=0;;) {
        while (r*r < N && sum < N) {
            ++r;
            sum += r*r;
        }
        if (sum == N) {
            ++ans_num;
            ans.push_back(P(l+1,r));
        }
        if (sum < N) {
            break;
        }
        ++l;
        sum -= l*l;
    }
    printf("%d\n",ans_num);
    for (int i=0; i<ans_num; ++i) {
        unsigned long long l = ans[i].first , r = ans[i].second;
        printf("%lld ",r-l+1);
        for (unsigned long long j=l; j<=r; ++j) {
            printf("%lld%c",j,j==r?'\n':' ');
        }
    }
}

int
main()
{
    scanf("%lld",&N);
    solve();
    return 0;
}