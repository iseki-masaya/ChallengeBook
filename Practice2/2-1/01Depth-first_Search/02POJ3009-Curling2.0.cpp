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

#define INF (1<<20)

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

pair<int, int> goal;

int
dfs(int x,int y,int dep,vector<vector<int> > &map)
{
	if (dep > 10)
		return INF;

	int res = INF;
	for (int i=0; i<4; ++i) {
		int cx = x,cy = y;
		bool isMove = false;
		while (true) {
			cx += dx[i]; cy += dy[i];
			if (cx < 0 || cx >= map[0].size() || cy < 0 || cy >= map.size() ) {
				break;
			}
			else if (map[cy][cx] == 1 && !isMove) {
				break;
			}
			else if (map[cy][cx] == 1 && isMove) {
				cx -= dx[i]; cy -= dy[i];
				map[cy+dy[i]][cx+dx[i]] = 0;
				res = min(res,dfs(cx, cy, dep+1, map));
				map[cy+dy[i]][cx+dx[i]] = 1;
				break;
			}
			else if (map[cy][cx] == 3) {
				res = min(res,dep+1);
				break;
			}
			isMove = true;
		}
	}

	return res;
}

pair<int, int>
search(vector<vector<int> > &map,int dst)
{
	for (int y=0; y<map.size(); ++y) {
		for (int x=0; x<map[0].size(); ++x) {
			if (map[y][x] == dst) {
				return make_pair(x, y);
			}
		}
	}
	return make_pair(-1, -1);
}

void
solve(int w,int h,vector<vector<int> > &map)
{
	pair<int, int> start = search(map,2);
	goal = search(map,3);
	int ans = dfs(start.first,start.second,0,map);
	printf("%d\n",ans>10?-1:ans);
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
		vector<vector<int> > map(h,vector<int>(w,0));
		for (int y=0; y<h; ++y) {
			for (int x=0; x<w; ++x) {
				scanf("%d",&map[y][x]);
			}
		}
		solve(w,h,map);
	}
}
