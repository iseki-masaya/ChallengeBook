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

#define MAX_W 103
#define MAX_H 103

bool used[MAX_H][MAX_W];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int H,W;

void
dps(int y,int x,char fruit,vector<string> &m)
{
	if (used[y][x] || m[y][x] != fruit) {
		return;
	}
	used[y][x] = true;
	for (int i=0; i<4; ++i) {
		int cx = x+dx[i],cy = y+dy[i];
		if (cx < 0 || cx >= W || cy < 0 || cy >= H) {
			continue;
		}
		dps(y+dy[i], x+dx[i], fruit, m);
	}
	return;
}

void
solve(vector<string> &m)
{
	memset(used, false, MAX_H*MAX_W);

	int ans = 0;
	for (int y=0; y<H; ++y) {
		for (int x=0; x<W; ++x) {
			if (!used[y][x]) {
				++ans;
				dps(y,x,m[y][x],m);
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	while(true) {
		scanf("%d %d",&H,&W);
		if (H==0 && W==0) {
			return 0;
		}
		vector<string> m(H);
		for (int i=0; i<H; ++i) {
			char str[256];
			scanf("%s%*c",str);
			m[i] = (string)str;
		}
		solve(m);
	}
}
