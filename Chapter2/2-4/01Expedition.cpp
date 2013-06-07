#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

struct GS
{
	int dist;
	int fuel;
};

struct comp
{
  bool operator()(const GS &lhs,const GS &rhs)
	{
		return lhs.dist > rhs.dist;
	}
};

int solve(vector<GS>&gs,int L,int P)
{
	priority_queue<int> q;
	comp c;
	sort(gs.begin(), gs.end(), c);

	int pos = 0,tank = P,ans = 0;
	for (int i=0; i<gs.size(); ++i) {
		int d = (L-gs.at(i).dist) - pos;

		while (tank - d <0) {
			if (q.empty()) {
				return -1;
			}
			tank += q.top();
			q.pop();
			++ans;
		}

		tank -= d;
		pos = L - gs.at(i).dist;
		q.push(gs.at(i).fuel);
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<GS> gs;
	GS tmp;
	tmp.fuel = 0; tmp.dist = 0;
	gs.push_back(tmp);
	for (int i=0; i<n; ++i) {
		cin >> tmp.dist >> tmp.fuel;
		gs.push_back(tmp);
	}
	int L,P;
	cin >> L >> P;
	cout << solve(gs,L,P) << endl;
}
