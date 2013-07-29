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

#define MAX_M 50003
#define MAX_X 303
#define MAX_Y 303

int M;

int X[MAX_M],Y[MAX_M],T[MAX_M];
const int dx[5] = {0,1,0,-1,0};
const int dy[5] = {1,0,-1,0,0};

int m[MAX_Y][MAX_X];

int
solve()
{
	memset(m, -1, sizeof(m));

	for (int i=0; i<M; ++i) {
		for (int j=0; j<5; ++j) {
			int cx = X[i]+dx[j] , cy = Y[i]+dy[j];
			if (cx < 0 || 301 <= cx || cy < 0 || 301 <= cy) {
				continue;
			}
			m[cy][cx] = m[cy][cx]==-1?T[i]:min(T[i],m[cy][cx]);
		}
	}

	if (m[0][0] == 0) {
		return -1;
	}

	int dist[MAX_Y][MAX_X];
	memset(dist, 0, sizeof(dist));

	bool used[MAX_Y][MAX_X] = {false};
	used[0][0] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (m[y][x] == -1) {
			return dist[y][x];
		}
		for (int i=0; i<4; ++i) {
			int cx = x + dx[i] , cy = y + dy[i];
			if (cx < 0 || cy < 0 || used[cy][cx] || (m[cy][cx]!=-1 && (dist[y][x] + 1) >= m[cy][cx]) ) {
				continue;
			}
			dist[cy][cx] = dist[y][x] + 1;
			used[cy][cx] = true;
			q.push(make_pair(cx, cy));
		}
	}
	return -1;
}

int
main()
{
	scanf("%d",&M);
	for (int i=0; i<M; ++i) {
		scanf("%d %d %d",&X[i],&Y[i],&T[i]);
	}
	printf("%d\n",solve());
}
