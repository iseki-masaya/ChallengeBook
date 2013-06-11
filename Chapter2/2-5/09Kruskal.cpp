#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class UnionFindTree {
	vector<int> parent,rank;
public:
	UnionFindTree(int n);
	int find(int x);
	void unite(int x,int y);
	bool same(int x,int y);
};

UnionFindTree::UnionFindTree(int n)
{
	parent = vector<int>(n);
	rank = vector<int>(n);
	for (int i=0; i<n; ++i) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int
UnionFindTree::find(int x)
{
	if (parent[x] == x) { //if x is root
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

void
UnionFindTree::unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}

	if (rank[x] < rank[y]) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
		if (rank[x] == rank[y]) {
			++rank[x];
		}
	}
}

bool
UnionFindTree::same(int x, int y)
{
	return find(x) == find(y);
}



struct edge {
  int to,from,cost;
};

vector<edge> es;
int V;

bool comp(const edge &lhs,const edge &rhs)
{
	return lhs.cost < rhs.cost;
}

int solve()
{
	sort(es.begin(), es.end(), comp);
	UnionFindTree uft(V);
	int ans = 0;
	for (int i=0; i<es.size(); ++i) {
		if (!uft.same(es[i].to, es[i].from)) {
			uft.unite(es[i].to, es[i].from);
			ans += es[i].cost;
		}
	}
	return ans;
}

int main()
{
	V = 7;
	vector<int> from = {0,0,1,1,1,1,2,3,3,3,4,4,5,5,5,5,6,6};
	vector<int> to = {1,6,0,2,3,5,1,1,4,5,3,5,1,3,4,6,0,5};
	vector<int> cost = {2,10,2,1,3,7,1,3,5,1,5,8,7,1,8,5,10,5};

	edge work;
	for (int i=0; i<to.size(); ++i) {
		work.to = to[i];
		work.from = from[i];
		work.cost = cost[i];
		es.push_back(work);
	}
	cout << solve() << endl;

	es.clear();


}
