#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>

#define MAX 50000 // 5133
#define SIZE 10000
#define INF (1<<30)

using namespace std;

const double g = 10.0;

double
calc(int T,int H)
{
	if (T < 0) {
		return H;
	}
	double t = sqrt(2*H/g);
	int k= static_cast<int>(T/t);
	if ((k&1)==0) {
		double d = T-k*t;
		return H-g*d*d/2;
	} else {
		double d = k*t + t - T;
		return H-g*d*d/2;
	}
}

void
solve(int N,int H,int R,int T)
{
	vector<double> y(N);
	for (int i=0; i<N; ++i) {
		y[i] = calc(T-i,H);
	}
	sort(y.begin(), y.end());
	for (int i=0; i<N; ++i) {
		printf("%.2f%c",y[i]+2*R*i/100.0,i+1==N?'\n':' ');
	}
}

int
main(void) {
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) {
		int N,H,R,T;
		scanf("%d %d %d %d",&N,&H,&R,&T);
		solve(N,H,R,T);
	}
}