#include <iostream>

using namespace std;

#define MAX 1000

int solve(int n,int m,int M)
{
	int dp[MAX+1][MAX+1] = {0};

	dp[0][0] = 1;
	for (int i=1; i<=m; ++i) {
		for (int j=0; j<=n; ++j) {
			if (j-i>=0) {
				dp[i][j] = dp[i-1][j]+dp[i][j-i];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[m][n]%M;
}

int main()
{
	int n = 4;
	int m = 3;
	int M = 10000;
	cout << solve(n,m,M) << endl;
}
