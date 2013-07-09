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

#define MAX 16
#define INF (1<<30)

using namespace std;

int opt[MAX][MAX];
int flip[MAX][MAX];

const int dx[5] = {1,0,0,0,-1};
const int dy[5] = {0,1,0,-1,0};

//if (x,y) is black, get return true;
bool
get_color(int x,int y,vector<vector<int> > &tile)
{
	int c = tile[y][x];
	for (int i=0; i<5; ++i) {
		int cx = x+dx[i],cy = y+dy[i];
		if (0 <= cx && cx < tile[0].size() && 0 <= cy && cy < tile.size()) {
			c += flip[cy][cx];
		}
	}
	return c&1;
}

int
calc(int N,int M,vector<vector<int> > &tile)
{
	for (int y=1; y<M; ++y) {
		for (int x=0; x<N; ++x) {
			if (get_color(x,y-1,tile)) {
				flip[y][x] = 1;
			}
		}
	}
	for (int x=0; x<N; ++x) {
		if (get_color(x, M-1, tile)) {
			return -1;
		}
	}
	int res = 0;
	for (int y=0; y<M; ++y) {
		for (int x=0; x<N; ++x) {
			res += flip[y][x];
		}
	}
	return res;
}

void
solve(int N,int M,vector<vector<int> > &tile)
{
	int res = -1;

	for (int i=0; i < 1<<N; ++i) {
		memset(flip, 0, sizeof(flip));
		for (int x=0; x<N; ++x) {
			flip[0][(N-1)-x] = (i>>x)&1;
		}
		int num = calc(N, M, tile);
		if (num >=0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}
	}

	if (res < 0) {
		printf("IMPOSSIBLE\n");
	}
	else {
		for (int y=0; y<M; ++y) {
			for (int x=0; x<N; ++x) {
				printf("%d%c",opt[y][x], x+1==N?'\n':' ');
			}
		}
	}
}

int
main(void) {
	int M,N;
	scanf("%d %d",&M,&N);
	vector<vector<int> > tile(M,vector<int>(N,0));
	for (int y=0; y<M; ++y) {
		for (int x=0; x<N; ++x) {
			scanf("%d",&tile[y][x]);
		}
	}
	solve(N,M,tile);
}