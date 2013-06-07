#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class UnionFindTree {
	vector<int> par;
	vector<int> rank;

public:
	UnionFindTree(int n);
	int find(int x);
	void unite(int x,int y);
	bool same(int x, int y);
};

UnionFindTree::UnionFindTree(int n)
{
	par = vector<int>(n);
	rank = vector<int>(n);
	for (int i=0; i<n; ++i) {
		par[i] = i;
		rank[i] = 0;
	}
}

int
UnionFindTree::find(int x)
{
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void
UnionFindTree::unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y]) ++rank[x];
	}
}

bool
UnionFindTree::same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);

	int ans = 0;
	UnionFindTree uft(N*3);
	for (int i=0; i<K; ++i) {
		int t,x,y;
		scanf("%d %d %d",&t,&x,&y);
		--x,--y;

		if (x < 0 || N <= x || y < 0 || N <= y) {
			++ans;
			continue;
		}

		if (t == 1) {
			// x same y
			if (uft.same(x,y+N) || uft.same(x,y+2*N)) {
				++ans;
			}
			else {
				uft.unite(x, y);
				uft.unite(x+N, y+N);
				uft.unite(x+2*N, y+2*N);
			}
		}
		else {
			// x eat y
			if (uft.same(x, y) || uft.same(x, y+2*N)) {
				++ans;
			}
			else {
				uft.unite(x, y+N);
				uft.unite(x+N, y+2*N);
				uft.unite(x+2*N, y);
			}
		}
	}

	printf("%d\n",ans);
}
