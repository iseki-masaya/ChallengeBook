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

using namespace std;

#define MAX_N 17
#define INF (1<<15)

int n;
int dp[1<<MAX_N][MAX_N];

void
solve(vector<vector<int> > &d)
{
	for (int S=0; S < 1<<n; ++S) {
		fill(dp[S], dp[S] + n, INF);
	}
	dp[(1<<n)-1][0] = 0;
	for (int S = (1<<n)-2; S >= 0; --S) {
		for (int v=0; v<n; ++v) {
			for (int u=0; u<n; ++u) {
				if (!(S>>u&1)) {
					dp[S][v] = min(dp[S][v], dp[S|(1<<u)][u] + d[v][u]);
				}
			}
		}
	}
	printf("%d\n",dp[0][0]);
}

int
main()
{
	n = 5;
	vector<vector<int> > d =
	{
		{0,3,INF,4,INF},
		{INF,0,5,INF,INF},
		{4,INF,0,5,INF},
		{INF,INF,INF,0,3},
		{7,6,INF,INF,0}
	};
	solve(d);
}
