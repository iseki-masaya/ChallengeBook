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

#define INF (1<<28)

using namespace std;

#define MAX_N 105

typedef pair<int, int> P;

int N;
int cost[MAX_N][MAX_N];

void
solve()
{
    bool used[MAX_N];
    memset(used, false, sizeof(used));
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,0));

    int ans = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        ans += p.first;

        for (int u=0; u<N; ++u) {
            if (!used[u]) {
                que.push(P(cost[v][u],u));
            }
        }
    }
    printf("%d\n",ans);
}

int
main()
{
    while (scanf("%d",&N) != EOF) {
        for (int i = 0; i<N; ++i) {
            fill(cost[i], cost[i]+N, INF);
        }
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                int c;
                scanf("%d",&c);
                cost[i][j] = c;
            }
        }
        solve();
    }
}