#include <vector>
#include <iostream>

using namespace std;

int solve(vector<int> w,vector<int> v,int weight)
{
	int n = static_cast<int>(w.size());
	int dp[101][10001] = {0};
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=weight; ++j) {
			if (j < w[i]){
				dp[i+1][j] = dp[i][j];
			}
			else {
				dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
			}
		}
	}

	return dp[n][weight];
}

int main(){
	vector<int> w = {3,4,2};
	vector<int> v = {4,5,3};
	int weight = 7;
	cout << solve(w, v, weight) << endl;
}