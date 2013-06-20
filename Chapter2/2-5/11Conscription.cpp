#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX_R 50050
#define MAX_V 20050

int par[MAX_V];
int rnk[MAX_V];

void
init(size_t size)
{
	for (int i=0; i<size; ++i) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int
find(int x)
{
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void
unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rnk[x] < rnk[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])
			++rnk[x];
	}
}

bool
same(int x,int y)
{
	return find(x) == find(y);
}

struct edge {
  int from,to,cost;
};

edge es[MAX_R];
int V,E;

bool comp(const edge &lhs,const edge &rhs)
{
	return lhs.cost < rhs.cost;
}

int kruskal()
{
	sort(es, es + E, comp);
	init(V);
	int ans = 0;
	for (int i=0; i<E; ++i) {
		if (!same(es[i].to, es[i].from)) {
			unite(es[i].to, es[i].from);
			ans += es[i].cost;
		}
	}

	return ans;
}

int main()
{
	int caseNum;
//	cin >> caseNum;
	scanf("%d",&caseNum);
	for (int i=0; i<caseNum; ++i) {
		int N,M,R;
//		cin >> N >> M >> R;
		scanf("%d %d %d",&N,&M,&R);
		int from,to,cost;

		for (int j=0; j<R; ++j) {
//			cin >> from >> to >> cost;
			scanf("%d %d %d",&from,&to,&cost);
			es[j] = (edge){from,N+to,-cost};
		}
		V = N + M;
		E = R;
//		cout << 10000*(N+M) + kruskal() << endl;
		printf("%d\n",10000*(N+M) + kruskal());
	}

	return 0;
}
