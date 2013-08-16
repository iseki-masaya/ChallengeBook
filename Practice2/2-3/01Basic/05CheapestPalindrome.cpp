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
#include <time.h>

using namespace std;

#define MAX_M 2005

int N,M;
vector<vector<int> > dp(MAX_M,vector<int>(MAX_M,0));
string ID;
int cost[30];

void
solve()
{
	for (int i=M-1; i>=0; --i) {
		for (int j=1; j<=M; ++j) {
			if ( j - i <= 0) {
				dp[i][j] = 0;
			}
			else if (ID[i]==ID[j]) {
				dp[i][j] = dp[i+1][j-1];
			}
			else {
				dp[i][j] = min(dp[i+1][j] + cost[ID[i]-'a'] , dp[i][j-1] + cost[ID[j]-'a']);
			}
		}
	}
	printf("%d\n",dp[0][M-1]);
}

int
main()
{
	scanf("%d %d",&N,&M);
	cin >> ID;
	for (int i=0; i<N; ++i) {
		char c;
		int add,del;
		scanf("%*c%c%*c %d %d",&c,&add,&del);
		cost[c-'a'] = min(add,del);
	}
	solve();
	return 0;
}