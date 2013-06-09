#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

#define MAX_V 50
#define INF 50000

using namespace std;

struct edge {
  int to,cost;
};

//first:cost second:vertex num
typedef pair<int, int> P;

vector<vector<edge> > G(MAX_V);
vector<int> d(MAX_V,INF);

int dijkstra(int s,int V,int g)
{
	priority_queue<P,vector<P>,greater<P> > que;
	d[s] = 0;
	que.push(P(0,s));

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i=0; i<G[v].size(); ++i) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}

	return d[g];
}

int main()
{
	int V = 7;
	vector<int> from = {0,0,1,1,1 ,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6};
	vector<int> to   = {1,2,2,3,4 ,0,0,1,3,1,2,5,1,5,6,3,4,6,4,5};
	vector<int> c = {2,5,4,6,10,2,5,4,2,6,2,1,10,3,5,1,3,9,5,9};
	edge e;
	for (int i=0; i<from.size(); ++i) {
		e.to = to[i];
		e.cost = c[i];
		G[from[i]].push_back(e);
	}

	cout << dijkstra(0, V, V-1) << endl;
}
