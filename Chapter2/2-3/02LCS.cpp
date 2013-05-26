#include <vector>
#include <iostream>

using namespace std;

class LCS {
public:
	int count(string s,string t)
	{
		int sizeX = static_cast<int>(s.size());
		int sizeY = static_cast<int>(t.size());
		vector<vector<int> > dp(sizeY+1,vector<int>(sizeX+1,0));
		for (int x=0; x<=s.size(); ++x) {
			for (int y=0; y<=t.size(); ++y) {
				dp[y][x] = 0;
			}
		}

		for (int y=1; y<=sizeY; ++y) {
			for (int x=1; x<=sizeX; ++x) {
				if (s[x-1]==t[y-1]) {
					dp[y][x] = max(dp[y-1][x-1]+1,max(dp[y-1][x],dp[y][x-1]));
				}
				else {
					dp[y][x] = max(dp[y-1][x],dp[y][x-1]);
				}
			}
		}

		return dp[sizeY][sizeX];
	}
};

int main(){
	LCS bp;
	string s,t;
	while (cin >> s >> t) {
		cout << bp.count(s,t) << endl;
	}
	return 0;
}