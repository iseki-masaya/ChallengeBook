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

#define INF (1<<30)

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

pair<int, int>
search(vector<string> &map)
{
	for (int y=0; y<map.size(); ++y) {
		for (int x=0; x<map[0].size(); ++x) {
			if (map[y][x] == '@') {
				return make_pair(x, y);
			}
		}
	}
	return make_pair(-1, -1);
}

void
solve(int w,int h,vector<string> &map)
{
	vector<vector<int> > used(h,vector<int> (w,false));
	queue<pair<int, int> > que;
	pair<int, int> man = search(map);
	used[man.second][man.first] = true;
	que.push(man);

	int ans=0;
	while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		que.pop();
		++ans;

		for (int i=0; i<4; ++i) {
			int cx = x+dx[i],cy = y + dy[i];
			if (cx < 0 || w <= cx || cy < 0 || h <= cy) {
				continue;
			}
			if (used[cy][cx] || map[cy][cx] == '#') {
				continue;
			}
			que.push(make_pair(cx, cy));
			used[cy][cx] = true;
		}
	}

	printf("%d\n",ans);
}

int
main()
{
	while (true) {
		int w,h;
		scanf("%d %d",&w,&h);
		if (w==0&&h==0) {
			return 0;
		}
		vector<string> map(h);
		char line[30];
		for (int i=0; i<h; ++i) {
			scanf("%s[^\\n]%*c",line);
			map[i] = (string)line;
		}
		solve(w,h,map);
	}
}
