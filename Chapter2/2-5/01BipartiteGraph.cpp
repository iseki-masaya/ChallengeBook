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

#define MAX_V 50

vector<vector<int> > G;
vector<int> color(MAX_V,0);

bool dfs(int v,int c)
{
	color[v] = c;
	for (int i=0; i<G[v].size(); ++i) {
		if (color[G[v][i]] == c) return false;
		if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}
	return true;
}

string solve()
{
	size_t V = G.size();
 	for (int i=0; i<V; ++i) {
		if (color[i] == 0) {
			if (!dfs(i,1)) {
				return "NO";
			}
		}
	}
	return "YES";
}

int main()
{
	G = vector<vector<int> >{{1,2},{0,2},{0,1}};
	cout << solve() << endl;
	color = vector<int>(MAX_V,0);
	G = vector<vector<int> >{{1,3},{0,2},{1,3},{0,2}};
	cout << solve() << endl;
}
