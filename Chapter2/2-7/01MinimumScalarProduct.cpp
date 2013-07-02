#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <fstream>
#include <istream>

using namespace std;

#define FILE

long long solve(vector<int> &v1,vector<int> &v2)
{
	long long ans1 = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());
	for (int i=0; i<v1.size(); ++i) {
		ans1 += static_cast<long long>(v1[i])*v2[i];
	}
	long long ans2 = 0;
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end());
	for (int i=0; i<v1.size(); ++i) {
		ans2 += static_cast<long long>(v1[i])*v2[i];
	}
	return ans1>ans2 ? ans1 : ans2;
}

int main()
{
	int num;
	ofstream ofs("/Users/iseki/Downloads/ans.dat");

#ifdef FILE
	ifstream ifs( "/Users/iseki/Downloads/A-large-practice (1).in" );
	ifs >> num;
#endif
#ifndef FILE
	cin >> num;
#endif

	for (int i=1; i<=num; ++i) {
		int size;
#ifdef FILE
		ifs >> size;
#endif
#ifndef FILE
		cin >> size;
#endif
		vector<int> v1(size),v2(size);
		for (int i=0; i<size; ++i) {
#ifdef FILE
			ifs >> v1[i];
#endif
#ifndef FILE
			cin >> v1[i];
#endif
		}
		for (int i=0; i<size; ++i) {
#ifdef FILE
			ifs >> v2[i];
#endif
#ifndef FILE
			cin >> v2[i];
#endif
		}
		long long ans = solve(v1,v2);
		printf("Case #%d: %lld\n",i,ans);
#ifdef FILE
		ofs << "Case #" << i << ": " << ans << endl;
#endif
	}

	return 0;
}