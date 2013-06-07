#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

long long solve(vector<int> &divide)
{
	priority_queue<int,vector<int>,greater<int> > q;
	for (int i=0; i<divide.size(); ++i) {
		q.push(divide.at(i));
	}

	int lhs,rhs;
	long long ans = 0;
	while (q.size()>1) {
		lhs = q.top();
		q.pop();
		rhs = q.top();
		q.pop();
		ans += static_cast<long long>(lhs + rhs);

		q.push(lhs+rhs);
	}

	return ans;
}

int main()
{
	int n,work;
	cin >> n;
	vector<int> divide(n);
	for (int i=0; i<n; ++i) {
		cin >> work;
		divide.at(i) = work;
	}
	cout << solve(divide) << endl;
}