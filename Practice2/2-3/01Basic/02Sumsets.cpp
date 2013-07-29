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

#define MAX 21

int dp[MAX];

void
solve(int n)
{
	vector<int> dp(n+1);
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for (int i=3; i<=n; ++i) {
		if (i&1) {
			dp[i] = dp[i-1];
		}
		else {
			dp[i] = dp[i/2] + dp[i-2];
			dp[i] %= 1000000000;
		}
	}
	printf("%d\n",dp[n]);
}

int main()
{
	int n;
	scanf("%d",&n);
	solve(n);
}
