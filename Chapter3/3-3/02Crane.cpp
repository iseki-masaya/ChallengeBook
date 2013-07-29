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

using namespace std;

#define INF (1<<20)
#define PI 3.14159265

const int ST_SIZE = (1<<15)-1;

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];
double prv[ST_SIZE];

void
init(int k,int l,int r,vector<int> &L)
{
	ang[k] = vx[k] = 0.0;
	if (r - l == 1) {
		vy[k] = L[l];
	}
	else {
		int chl = k*2+1 , chr = k*2+2;
		init(chl,l,(l+r)/2,L);
		init(chr,(l+r)/2, r, L);
		vy[k] = vy[chl]+vy[chr];
	}
}

void
change(int s,double a,int v,int l,int r)
{
	if (s <= l) {
		return;
	}
	else if (s < r) {
		int chl = v*2+1,chr = v*2+2;
		int m = (l+r)/2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if (s <= m) {
			ang[v] += a;
		}
		double s = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[chl] + (c*vx[chr] - s*vy[chr]);
		vy[v] = vy[chl] + (s*vx[chr] + c*vy[chr]);
	}
}

void
solve(int N,int C,vector<int>&L,vector<int>&S,vector<int>&A)
{
	init(0, 0, N, L);
	for (int i=1; i<N; ++i) {
		prv[i] = PI;
	}
	for (int i=0; i<C; ++i) {
		int s = S[i];
		double a = A[i]/360.0 * 2 * PI;

		change(s, a-prv[s], 0, 0, N);
		prv[s] = a;

		printf("%.2f %.2f\n",vx[0],vy[0]);
	}
}

int
main()
{
	int N,C;
	while (scanf("%d %d",&N,&C) != EOF) {
		vector<int> L(N);
		for (int i=0; i<N; ++i) {
			scanf("%d",&L[i]);
		}
		vector<int> S(C),A(C);
		for (int i=0; i<C; ++i) {
			scanf("%d %d",&S[i],&A[i]);
		}
		solve(N,C,L,S,A);
		printf("\n");
	}
}
