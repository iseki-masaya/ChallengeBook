#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_V 101
#define INF (1<<20)

int V; //頂点数
vector<int> G[MAX_V]; //グラフの隣接リスト表現
int match[MAX_V]; //マッチングのペア
bool used[MAX_V]; //DFSですでに調べたかのフラグ

// uとvを結ぶ辺をグラフに追加する
void
add_edge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

//増加パスをDFSで探す
bool
dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || (!used[w] && dfs(w))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

//二部グラフの最大マッチングを求める。
int
bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v=0; v < V; ++v) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v)) {
				++res;
			}
		}
	}
	return res;
}

int
main()
{
	V = 6;
	vector<vector<int> >  g =
	{
		{0,1},
		{0,2},
		{2}
	}
	;
	for (int i=0; i<g.size(); ++i) {
		for (int j=0; j<g[i].size(); ++j) {
			add_edge(i, g[i][j]);
		}
	}
	cout << bipartite_matching() << endl;
}