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
#include <numeric>

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_X 15
#define MAX_Y 15

int X,Y;
bool m[MAX_Y][MAX_X];

bool
init()
{
    scanf("%d%d",&Y,&X);
    for (int y=0; y<Y; ++y) {
        for (int x=0; x<X; ++x) {
            scanf("%d",&m[y][x]);
        }
    }
    return true;
}

bool
check_adj(int next,int prev,int y)
{
    if (next&prev) {
        return false;
    }
    for (int i=0; i<31; ++i) {
        if ( (next>>i & 3) == 3 ) {
            return false;
        }
        if ( (next>>i & 1) && !m[y][i] ) {
            return false;
        }
    }
    return true;
}

int
solve()
{
    vector<vector<long long> > dp(2,vector<long long>(1<<X,0));
    dp[0][0] = 1;

    for (int y=0; y<Y; ++y) {
        for (int prev=0; prev<(1<<X); ++prev) if(dp[y&1][prev] != 0) {
            for (int next=0; next<(1<<X); ++next) if(check_adj(next,prev,y)) {
                dp[(y+1)&1][next] = (dp[(y+1)&1][next] + dp[y&1][prev])%MOD;
            }
        }
        fill(dp[y&1].begin(), dp[y&1].end(), 0);
    }
    long long ans = 0;
    for (int x=0; x<(1<<X); ++x) {
        ans = (ans + dp[Y&1][x])%MOD;
    }
    return (int)ans;
}

int
main()
{
    init();
    printf("%d\n",solve());
    return 0;
}