#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1001
#define MAX_M 1001

int dp[MAX_N][MAX_M] = {0};

int solve(int n,int m,vector<int> a,int M)
{
	for (int i=0; i<=n; ++i) {
		dp[i][0] = 1;
	}
	for (int i=0; i<n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (j-1-a[i] >= 0) {
				dp[i+1][j] = (dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]] + M)%M;
			}
			else {
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j])%M;
			}
		}
	}

	return dp[n][m];
}

int main()
{
	int n = 3;
	int m = 3;
	vector<int> a={1,2,3};
	int M = 10000;
	cout << solve(n,m,a,M) << endl;
}
