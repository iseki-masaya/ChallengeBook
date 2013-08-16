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

int N,M;
int d[2005][2005];
string ID;
int cost[30];

int
dfs(int l,int r)
{
	if (r-l <= 0)
		return 0;
	if (ID[l] == ID[r])
		return dfs(l+1, r-1);
	else
		return min(dfs(l+1, r) + cost[ID[l]-'a'] , dfs(l, r-1) + cost[ID[r]-'a']);
}

void
solve()
{
	printf("%d\n",dfs(0, M-1));
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
}