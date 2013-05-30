#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define INF 10e7

int solve(vector<int> &a)
{
	int res = 0;
	int n = static_cast<int>(a.size());
	int dp[MAX_N+1] = {0};
	for (int i=0; i<n; ++i) {
		dp[i] = 1;
		for (int j=0; j<=i; ++j)
			if(a[i] > a[j])
				dp[i] = max(dp[i],dp[j]+1);

		res = max(res,dp[i]);
	}

	return res;
}

int solve2(vector<int> &a)
{
	vector<int> dp(MAX_N,INF);
	for (int i=0; i<a.size(); ++i) {
		*(lower_bound(dp.begin(),dp.end(),a[i])) = a[i];
	}
	return static_cast<int>(distance(dp.begin(),lower_bound(dp.begin(), dp.end(), INF)));
}

int main()
{
	vector<int> a = {4,2,3,1,5,645,6453756,3452,435645,3456,345,6,325,2,56,2546,3,643,6,3574,654,34563,5463};
	cout << solve(a) << endl;
	cout << solve2(a) << endl;
}
