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

#define MAX_H 1003
#define MAX_W 1003

int H,W,N;
vector<string> m;
bool used[MAX_H][MAX_W];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct state {
  int x,y,cnt;
};

state
search()
{
	state work;
	for (int y=0; y<H; ++y) {
		for (int x=0; x<W; ++x) {
			if (m[y][x] == 'S') {
				work.x = x;
				work.y = y;
				work.cnt = 0;
				return work;
			}
		}
	}
	return state();
}

state
setState(int x,int y,int cnt)
{
	state s;
	s.x = x;
	s.y = y;
	s.cnt = cnt;
	return s;
}

void
solve()
{
	memset(used, false, MAX_H*MAX_W);
	queue<state> q;
	q.push(search());

	int tar = 1;
	while (!q.empty()) {
		state work = q.front();
		q.pop();
		for (int i=0; i<4 ; ++i) {
			int cx = work.x + dx[i];
			int cy = work.y + dy[i];
			if (cx < 0 || W <= cx || cy < 0 || H <= cy || used[cy][cx] || m[cy][cx] == 'X') {
				continue;
			}
			if ( tar == static_cast<int>(m[cy][cx]-'0') ) {
				if (tar == N) {
					printf("%d\n",++work.cnt);
				}
				++tar;
				memset(used, false, MAX_H*MAX_W);
				queue<state> empty;
				swap(q, empty);
				used[cy][cx] = true;
				q.push(setState(cx,cy,work.cnt+1));
				break;
			}
			used[cy][cx] = true;
			q.push(setState(cx, cy, work.cnt+1));
		}
	}
}

int
main()
{
	scanf("%d %d %d",&H,&W,&N);
	char s[1056];
	m.resize(H);
	for (int i=0; i<H; ++i) {
		scanf("%s",s);
		m[i] = static_cast<string>(s);
	}
	solve();
}

