#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 100
#define MAX_V 100
#define INF 1000000

int solve(vector<int> &w,vector<int> &v,int W)
{
	int n = static_cast<int>(w.size());
	vector<vector<int> > dp(MAX_N+1,vector<int>(MAX_N*MAX_V+1,INF));
	dp[0][0] = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=MAX_N*MAX_V; ++j) {
			if (j < v[i]) {
				dp[i+1][j] = dp[i][j];
			}
			else {
				dp[i+1][j] = min(dp[i][j],dp[i][j - v[i]]+w[i]);
			}
		}
	}

	int res = 0;
	for (int i=0; i<=MAX_N*MAX_V; ++i)
		if (dp[n][i] <= W)
			res = i;

	return res;
}

int main()
{
	vector<int> w = {2,1,3,2};
	vector<int> v = {3,2,4,2};
	int W = 5;

	cout << solve(w,v,W) << endl;
}