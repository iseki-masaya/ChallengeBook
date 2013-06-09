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

vector<vector<int> > cost(MAX_V,vector<int>(MAX_V,INF));
vector<int> d(MAX_V,INF);
bool used[MAX_V] = {false};

int dijkstra(int s,int V,int g)
{
	d[s] = 0;
	while (true) {
		int v = -1;
		for (int u=0; u<V; ++u) {
			if (!used[u] && (v==-1 || d[v] > d[u])) v = u;
		}

		if (v==-1) break;

		used[v] = true;

		for (int u=0; u<V; ++u) {
			d[u] = min(d[u],d[v]+cost[v][u]);
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
	for (int i=0; i<from.size(); ++i) {
		cost[from[i]][to[i]] = c[i];
	}

	cout << dijkstra(0, V, V-1) << endl;
}
