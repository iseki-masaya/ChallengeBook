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

#define INF 9000
#define MAX_V 100

int mincost[MAX_V];
bool used[MAX_V];

int solve(vector<vector<int> >&cost)
{
	int V = static_cast<int>(cost.size());
	for (int i=0; i<V; ++i) {
		mincost[i] = INF;
		used[i] = false;
	}

	mincost[0] = 0;
	int ans = 0;
	while (true) {
		int v = -1;
		for (int u=0; u<V; ++u) {
			if (!used[u] && (v==-1 || mincost[u] < mincost[v]))
				v = u;
		}

		if (v == -1)
			break;

		used[v] = true;
		ans += mincost[v];

		for (int u=0; u<V; ++u) {
			mincost[u] = min(mincost[u],cost[v][u]);
		}
	}
	return ans;
}

int main()
{
	vector<vector<int> > cost =
	{
		{INF,2,INF,INF,INF,INF,10},
		{2,INF,1,3,INF,7,INF},
		{INF,1,INF,INF,INF,INF,INF},
		{INF,3,INF,INF,5,1,INF},
		{INF,INF,INF,5,INF,8,INF},
		{INF,7,INF,1,8,INF,5},
		{10,INF,INF,INF,INF,5,INF}
	};

	cout << solve(cost) << endl;

	cost = vector<vector<int> >
	{
		{INF,2,INF,INF,INF,INF,5},
		{2,INF,10,INF,INF,6,4},
		{INF,10,INF,5,3,INF,INF},
		{INF,INF,5,INF,9,INF,INF},
		{INF,INF,3,9,INF,1,INF},
		{INF,6,INF,INF,1,INF,2},
		{5,4,INF,INF,INF,2,INF}
	};

	cout << solve(cost) << endl;
}
