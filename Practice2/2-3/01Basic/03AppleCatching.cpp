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

#define MAX_W 33
#define MAX_T 1003

void
solve(int T,int W,vector<int> &drop)
{
	int dp[2][MAX_T][MAX_W];
	memset(dp, 0, sizeof(dp));
	int t = (drop[0]%2), inv_t;
	dp[t][0][0] = 1;
	for (int i=1; i<T; ++i) {
		t = (drop[i]%2);
		inv_t = ((t+1)%2);
		dp[t][i][0] = dp[t][i-1][0]+1;
		for (int j=0; j<=W; ++j) {
			if (dp[t][i-1][j] != 0) {
				dp[t][i][j] = dp[t][i-1][j]+1;
			}
			dp[inv_t][i][j] = dp[inv_t][i-1][j];
		}
		for (int j=1; j<=W; ++j) {
			if (dp[inv_t][i-1][j-1] != 0) {
				dp[t][i][j] = max(dp[t][i][j],dp[inv_t][i-1][j-1]+1);
			}
		}
	}
	int ans = 0;
	for (int i=0; i<T; ++i) {
		for (int j=0; j<=W; ++j) {
			ans = max(ans,max(dp[0][i][j],dp[1][i][j]));
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int T,W;
	scanf("%d %d",&T,&W);
	vector<int> drop(T);
	for (int i=0; i<T; ++i) {
		scanf("%d",&drop[i]);
	}
	solve(T,W,drop);
}