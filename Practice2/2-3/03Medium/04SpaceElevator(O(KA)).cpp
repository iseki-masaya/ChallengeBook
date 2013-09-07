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
#include <numeric>

using namespace std;

#define MAX_K 405
#define MAX_C 15
#define MAX_A 40505

struct S {
  int h,a,c;
    S(int h,int a,int c) : h(h),a(a),c(c)
    { }
};
vector<S> block;
int K;

bool
comp(const S &lhs,const S &rhs)
{
    if (lhs.a == rhs.a) {
        return lhs.h < rhs.h;
    }
    return lhs.a < rhs.a;
}

void
solve()
{
    sort(block.begin(), block.end(), comp);
    int dp[MAX_A];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int res = 0;
    for (int i=0; i<K; ++i) {
        for (int j=0; j<=block[i].a; ++j) {
            if (dp[j] >= 0) {
                dp[j] = block[i].c;
            }
            else if (j < block[i].h || dp[j-block[i].h] <= 0) {
                dp[j] = -1;
            }
            else {
                dp[j] = dp[j-block[i].h] - 1;
                res = max(res,j);
            }
        }
    }
    printf("%d\n",res);
}

int
main()
{
    scanf("%d",&K);
    for (int i=0; i<K; ++i) {
        int h,a,c;
        scanf("%d %d %d",&h,&a,&c);
        block.push_back(S(h,a,c));
    }
    solve();
}