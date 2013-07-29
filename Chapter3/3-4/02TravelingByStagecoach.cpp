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

#define MAX_N 9
#define MAX_M 33
#define INF 1e20

int n,m,a,b;
int t[MAX_N];
int d[MAX_M][MAX_M];

double dp[1<<MAX_N][MAX_M];

void
solve()
{
	for (int i=0; i< 1<<n; ++i) {
		fill(dp[i], dp[i]+m, INF);
	}
	dp[(1<<n)-1][a-1] = 0;
	double res = INF;
	for (int S = (1<<n)-1; S >= 0; --S) {
		res = min(res,dp[S][b-1]);
		for (int v=0; v<m; ++v) {
			for (int i=0; i<n; ++i) {
				if (S >> i & 1) {
					for (int u=0; u<m; ++u) {
						if (d[v][u] >= 0) {
							dp[S & ~(1<<i)][u] = min(dp[S & ~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
						}
					}
				}
			}
		}
	}

	if (res == INF) {
		printf("Impossible\n");
	}
	else {
		printf("%.3f\n",res);
	}
}

int
main()
{
	int p;
	while (true) {
		memset(d, -1, sizeof(d));
		scanf("%d %d %d %d %d",&n,&m,&p,&a,&b);
		if (n==0 && m==0 && p==0 && a==0 && b==0) {
			return 0;
		}
		for (int i=0; i<n; ++i) {
			scanf("%d",&t[i]);
		}
		for (int i=0; i<p; ++i) {
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			--x , --y;
			d[x][y] = z;
			d[y][x] = z;
		}
		solve();
	}
}
