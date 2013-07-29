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

#define MAX_N 16
#define MAX_M 16

int dp[2][1<<MAX_M];
bool color[MAX_N][MAX_M];
int n,m,M;

void
solve()
{
	int *crt = dp[0] , *next = dp[1];
	crt[0] = 1;
	for (int i=n-1; i>=0; --i) {
		for (int j=m-1; j>=0; --j) {
			for (int used = 0; used < 1<<m; ++used) {
				if ((used>>j&1) || color[i][j]) {
					next[used] = crt[used&~(1<<j)];
				}
				else {
					int res = 0;
					if (j+1<m && !(used>>(j+1)&1) && !color[i][j+1]) {
						res += crt[used|1<<(j+1)];
					}
					if (i+1<n && !color[i][j]) {
						res += crt[used|1<<j];
					}
					next[used] = res%M;
				}
			}
			swap(crt, next);
		}
	}
	printf("%d\n",crt[0]);
}

int
main()
{
	scanf("%d %d %d",&n,&m,&M);
	memset(color, false, sizeof(color));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			char s;
			scanf("%*c%c",&s);
			if (s == 'x') {
				color[i][j] = true;
			}
		}
	}
	solve();
}