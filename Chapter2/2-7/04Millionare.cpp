#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

//#define FILE

#define INF (1<<20)
#define MAX_M 15

using namespace std;

ofstream ofs("/Users/iseki/Downloads/ans.dat");
#ifdef FILE
ifstream ifs( "/Users/iseki/Downloads/C-small-practice (4).in" );
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
//	ofs << str << i << ": " << arg << endl;
	ofs << arg << endl;
	cout << str << i << ": " << arg << endl;
}

double
solve(int M,double P,int X)
{
	double dp[2][(1<<MAX_M)+1];
	int n = 1 << M;
	double *prv = dp[0],*nxt = dp[1];
	memset(prv, 0, sizeof(double)*(n+1));
	prv[n] = 1.0;

	for (int r=0; r<M; ++r) {
		for (int i=0; i<=n; ++i) {
			int jub = min(i,n-i);
			double t = 0.0;
			for (int j=0; j <= jub; ++j) {
				t = max(t,P*prv[i+j]+(1-P)*prv[i-j]);
			}
			nxt[i] = t;
		}
		for (int i=0; i<=n; ++i) {
			cout << "#" << i << ":" << nxt[i] << " ";
		}
		cout << endl;
		swap(prv, nxt);
	}

	int i = (int)static_cast<long long>(X*n)/1000000;
	return prv[i];
}

int
main()
{
	int num;
	in(num);

	for (int i=1; i<=num; ++i) {
		int M;
		in(M);
		double P;
		in(P);
		int X;
		in(X);

		double ans = solve(M,P,X);
		out(ans,i);
	}

	return 0;
}