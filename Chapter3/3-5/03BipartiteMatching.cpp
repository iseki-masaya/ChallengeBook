#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define MAX_V 101
#define MAX_N 50
#define MAX_K 50
#define INF (1<<20)

//to:行き先,cap:容量,rev:逆(G[e.to][e.rev]で逆辺の構造体にアクセスできる。)
struct edge {
  int to,cap,rev;
};

vector<edge> G[MAX_V];
int level[MAX_V]; //sからの距離
int iter[MAX_V];  //どこまで調べ終わったか
int N,K;
bool can[MAX_N][MAX_K]; //can[i][j]:=コンピュータiが仕事jをこなせる

//辺を追加。revは,相互参照できるようにしている。sizeで実現しているが、別のルールを用いても良い(i.e ハッシュ)。逆辺の逆辺は通常の辺である。
void
add_edge(int from,int to,int cap)
{
	G[from].push_back( (edge){ to,cap,(int)G[to].size() } );
	G[to].push_back( (edge){ from,0,(int)G[from].size()-1});
}

//sからの最短距離を幅優先で調べる
void
bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int i=0; i<G[v].size(); ++i) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
int
dfs(int v,int t,int f)
{
	if (v==t)
		return f;
	for (int i = iter[v]; i < G[v].size(); ++i) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f,e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

//sからtへの最大流量を返す。
int
max_flow(int s,int t)
{
	int flow = 0;
	for (;;) {
		bfs(s);
		if (level[t] < 0)
			return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f=dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

void
solve()
{
	// 0~N-1:コンピュータに対応する頂点
	// N~N+K-1:仕事に対応する頂点
	int s = N+K, t = s + 1;

	//sとコンピュータを結ぶ
	for (int i=0; i<N; ++i) {
		add_edge(s, i, 1);
	}

	//仕事とtを結ぶ
	for (int i=0; i<K; ++i) {
		add_edge(N+i, t, 1);
	}

	//コンピュータと仕事を結ぶ
	for (int i=0; i<N; ++i) {
		for (int j=0; j<K; ++j) {
			if (can[i][j]) {
				add_edge(i, N+j, 1);
			}
		}
	}

	printf("%d\n",max_flow(s, t));
}

int
main()
{
	N = 3;
	K = 3;
	vector<vector<int> >  c =
	{
		{1,1,0},
		{1,0,1},
		{0,1,0}
	}
	;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<K; ++j) {
			can[i][j] = c[i][j];
		}
	}
	solve();
}