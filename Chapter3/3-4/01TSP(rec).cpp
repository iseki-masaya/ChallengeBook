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

int
rec(int S,int v,vector<vector<int> >&d)
{
	if (dp[S][v] >= 0) {
		return dp[S][v];
	}

	if (S == (1<<n)-1 && v==0) {
		return dp[S][v] = 0;
	}

	int res = INF;
	for (int u=0; u<n; ++u) {
		if (!((S>>u)&1)) {
			res = min(res,rec(S|(1<<u), u,d) + d[v][u]);
		}
	}
	return dp[S][v] = res;
}

void
solve(vector<vector<int> > &d)
{
	memset(dp, -1, sizeof(dp));
	printf("%d\n",rec(0, 0,d));
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
