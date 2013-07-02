#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#define FILE

#define INF (1<<20)
#define MAX 105

using namespace std;

ofstream ofs("/Users/iseki/Downloads/ans.dat");
#ifdef FILE
ifstream ifs( "/Users/iseki/Downloads/C-small-practice (2).in" );
#endif

template <typename T>
void
in(T &arg) {
#ifdef FILE
	ifs >> arg;
#endif
#ifndef FILE
	cin >> arg;
#endif
}

template <typename T>
void
out(T &arg,int i) {
	string str = "Case #";
	ofs << str << i << ": " << arg << endl;
	cout << str << i << ": " << arg << endl;
}

int
solve(int P,int Q,vector<int> &A)
{
	int dp[MAX][MAX] = {0};
	for (int q=0; q<=Q; ++q) {
		dp[q][q+1] = 0;
	}

	for (int w = 2; w<=Q+1; ++w) {
		for (int i=0; i+w<=Q+1; ++i) {
			int j = i+w, t=INF;
			for (int k= i+1; k<j; ++k) {
				t = min(t,dp[i][k]+dp[k][j]);
			}
			dp[i][j] = t + A[j] - A[i] - 2;
		}
	}

	return dp[0][Q+1];
}

int
main()
{
	int num;
	in(num);

	for (int i=1; i<=num; ++i) {
		int P;
		in(P);
		int Q;
		in(Q);
		vector<int> A;
		A.push_back(0);
		for (int j=0; j<Q; ++j) {
			int work;
			in(work);
			A.push_back(work);
		}
		A.push_back(P+1);

		int ans = solve(P,Q,A);
		out(ans,i);
	}

	return 0;
}