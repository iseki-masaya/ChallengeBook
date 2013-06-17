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

#define MAX_N 5009
#define INF (1<<30)

typedef pair<int, int> P;

struct edge {
  size_t to;
	int cost;
};

vector<vector<edge> > G(MAX_N);
vector<long long> dist(MAX_N,INF);
vector<long long> dist2(MAX_N,INF);

long long solve(int N)
{
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dist.begin(), dist.end(), INF);
	fill(dist2.begin(), dist2.end(), INF);
	dist[0] = 0;
	que.push(P(0,0));

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d)
			continue;
		for (int i=0; i<G[v].size(); ++i) {
			edge &e = G[v][i];
			long long d2 = d + e.cost;
			if (dist[e.to] > d2) {
				swap(dist[e.to], d2);
				que.push(P(dist[e.to],e.to));
			}
			if (dist2[e.to] > d2 && dist[e.to] < d2) {
				dist2[e.to] = d2;
				que.push(P(dist2[e.to],e.to));
			}
		}
	}

	return dist2[N-1];
}

int main()
{
	int N,R;
	cin >> N >> R;
	for (int i=0; i<R; ++i) {
		size_t from;
		edge e;
		cin >> from >> e.to >> e.cost;
		--from; --e.to;
		G[from].push_back(e);
		swap(e.to, from);
		G[from].push_back(e);
	}
	cout << solve(N) << endl;
}
