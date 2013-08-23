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

#define MAX_N 15
#define INF (1<<28)

int V;
int cost[MAX_N][MAX_N];

int
solve()
{
    vector<vector<int> > dp(1<<V,vector<int>(V,INF));
    int mask_limit = 1<<V;

    dp[0][0] = 0;

    for (int mask = 0; mask < mask_limit ; ++mask) {
        for (int u = 0; u<V; ++u) {
            if (dp[mask][u] < INF) {
                int t = dp[mask][u];
                for (int v = 0; v<V; ++v) {
                    int nt = t + cost[u][v];
                    if (dp[mask|(1<<v)][v] > nt) {
                        dp[mask|(1<<v)][v] = nt;
                    }
                }
            }
        }
    }

    return dp[(1<<V)-1][0];
}

int
main()
{
    vector<vector<int> > c =
    {
        {0  ,3  ,INF,4  ,INF},
        {INF,0  ,5  ,INF,INF},
        {4  ,INF,0  ,5  ,INF},
        {INF,INF,INF,0  ,3},
        {7  ,6  ,INF,INF,0}
    };
    V = static_cast<int>(c.size());
    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            cost[i][j] = c[i][j];
        }
    }
    cout << solve() << endl;
}