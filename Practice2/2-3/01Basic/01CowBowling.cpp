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

#define MAX 351

int dp[2][MAX];

int main()
{
	memset(dp, 0, 2*MAX);
	int num;
	scanf("%d",&num);
	for (int i=1; i<=num; ++i) {
		for (int j=1; j<=i*2; j+=2) {
			int a;
			scanf("%d",&a);
			dp[0][j/2] = max(dp[1][max(0,(j-2)/2)]+a,dp[1][(j-1)/2]+a);
		}
		swap(dp[0], dp[1]);
	}
	int ans = 0;
	for (int i=0; i<=num; ++i) {
		ans = max(ans,dp[1][i]);
	}
	printf("%d\n",ans);
}
