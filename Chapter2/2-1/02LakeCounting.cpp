#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <bitset>

using namespace std;

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,1,0,-1,1,0,-1};
int memo[101][101] = {0};

class LakeCounting
{
private:
	int sizeY,sizeX;
	vector<string> map;
public:
	bool check(int x,int y,int key)
	{
		if(x<0 || x>=sizeX || y<0 || y>=sizeY) return false;
		if(map[y][x] != 'W') return false;
		if(memo[y][x] != 0) return false;

		memo[y][x] = key;

		for (int i=0; i<8; ++i) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			check(cx, cy, key);
		}

		return true;
	}

	int getNum(int N,int M,vector<string> map)
	{
		this->sizeY = N;
		this->sizeX = M;
		this->map = map;
		int key = 1;
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				if (map[y][x] == 'W') {
					if (check(x, y, key)) {
						++key;
					}
				}
			}
		}

		return key-1;
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

	LakeCounting lc;

	cout << lc.getNum(N, M, vec) << endl;
}