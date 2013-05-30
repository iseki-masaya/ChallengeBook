#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_K 100000

int dp[MAX_K+1];

string solve(vector<int> &a,vector<int> &m,int K)
{
	int n = static_cast<int>(a.size());
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=K; ++j) {
			if (dp[j] >= 0) {
				dp[j] = m[i];
			}
			else if (j<a[i] || dp[j-a[i]] <= 0) {
				dp[j] = -1;
			}
			else {
				dp[j] = dp[j-a[i]] - 1;
			}
		}
	}

	return dp[K]<0?"No":"YES";
}

int main()
{
	vector<int> a = {3,5,8};
	vector<int> m = {3,2,2};
	int K = 17;

	cout << solve(a,m,K) << endl;
}
