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

vector<vector<int> > d(MAX_V,vector<int>(MAX_V,INF));

int warshallFloyd(int V,int s,int g)
{
	for (int k=0;k<V;++k)
		for (int i=0;i<V;++i)
			for (int j=0;j<V;++j)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	return d[s][g];
}

int main()
{
	int V = 7;
	vector<int> from = {0,0,1,1,1 ,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6};
	vector<int> to   = {1,2,2,3,4 ,0,0,1,3,1,2,5,1,5,6,3,4,6,4,5};
	vector<int> c = {2,5,4,6,10,2,5,4,2,6,2,1,10,3,5,1,3,9,5,9};
	for (int i=0; i<from.size(); ++i) {
		d[from[i]][to[i]] = c[i];
	}
	for (int i=0; i<V; ++i) {
		d[i][i] = 0;
	}

	cout << warshallFloyd(V, 0, V-1) << endl;
}
