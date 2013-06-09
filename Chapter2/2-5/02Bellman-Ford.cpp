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
  int from,to,cost;
};

vector<edge> es;

int solve(int s,int g)
{
	vector<int> d(MAX_V,INF);
	d[s] = 0;

	while (true) {
		bool isUpdate = false;
		for (int i=0; i<es.size(); ++i) {
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from]+e.cost) {
				d[e.to] = d[e.from] + e.cost;
				isUpdate = true;
			}
		}
		if (!isUpdate)
			break;
	}

	return d[g];
}

int main()
{
	vector<int> from =	{0,1,2,1,3,3,4};
	vector<int> to =		{1,2,0,3,0,4,1};
	vector<int> cost =	{7,2,4,5,2,6,2};
	edge e;

	for (int i=0; i<from.size(); ++i) {
		e.from = from[i];
		e.to = to[i];
		e.cost = cost[i];
		es.push_back(e);
	}

	cout << solve(0,2) << endl;
}
