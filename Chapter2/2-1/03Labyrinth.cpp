#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

class Labyrinth
{
private:
	struct Point{
		int x;
		int y;
		int depth;
	};
public:
	int getPath(int N,int M,vector<string> &map)
	{
		bool memo[101][101] = {false};

		int sx,sy,gx,gy;
		for(int y=0;y<N;++y) {
			for(int x=0;x<M;++x) {
				if(map[y][x] == 'S') {
					sx = x;
					sy = y;
				}
				if(map[y][x] == 'G') {
					gx = x;
					gy = y;
				}
			}
		}

		memo[sy][sx] = true;

		int cx,cy;
		Point p,pp;
		p.x = sx; p.y = sy; p.depth = 0;
		queue<Point> q;
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			q.pop();

			if (p.x==gx && p.y==gy) {
				return p.depth;
			}

			for (int i=0; i<4; ++i) {
				cx = p.x + dx[i];
				cy = p.y + dy[i];
				if(cx<0 || cx >= M || cy<0 || cy >= N) continue;
				if(memo[cy][cx]) continue;
				if(map[cy][cx] == '#') continue;

				memo[cy][cx] = true;

				pp.x = cx; pp.y = cy; pp.depth = p.depth + 1;
				q.push(pp);
			}
		}

		return 220;
	}
};

int main()
{
	int N,M;
	cin >> N >> M;
	vector<string> vec;
	for (int i=0; i<N; ++i) {
		string str;
		cin >> str;
		vec.push_back(str);
	}

	Labyrinth l;

	cout << l.getPath(N, M, vec) << endl;
}