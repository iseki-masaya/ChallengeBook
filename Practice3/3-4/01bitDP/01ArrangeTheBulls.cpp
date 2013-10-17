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

using namespace std;

int N,M;
vector<vector<int> > fav;

bool
init()
{
    scanf("%d%d",&N,&M);
    fav.resize(N);
    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d",&p);
        for (int j=0; j<p; ++j) {
            int v;
            scanf("%d",&v);
            fav[i].push_back(v-1);
        }
    }
    return true;
}

int
solve()
{
    vector<vector<int> > dp(2,vector<int>(1<<M));
    dp[0][0] = 1;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<fav[i].size(); ++j) {
            int bit = (1<<fav[i][j]);
            for (int s=0; s<(1<<M); ++s) {
                if (!(s & bit)) {
                    dp[(i+1)&1][s|bit] += dp[i&1][s];
                }
            }
        }
        fill(dp[i&1].begin(), dp[i&1].end(), 0);
    }
    return accumulate(dp[N&1].begin(), dp[N&1].end(), 0);
}

int
main()
{
    init();
    printf("%d\n",solve());
    return 0;
}