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

typedef vector<int> vec;
typedef vector<vec> mat;

#define MAX_N 31

int n,M,k;
mat A(MAX_N,vec(MAX_N));

mat
mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size()));
	for (int i=0; i<A.size(); ++i) {
		for (int k=0; k<B.size(); ++k) {
			for (int j=0; j<B[0].size(); ++j) {
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;
			}
		}
	}
	return C;
}

mat
pow(mat A,long long n)
{
	mat B(A.size(),vec(A.size()));
	for (int i=0; i<A.size(); ++i) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n&1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}


void
solve()
{
	mat B(2*n,vec(2*n));
	for (int y=0; y<n; ++y) {
		for (int x=0; x<n; ++x) {
			B[y][x] = A[y][x];
		}
		B[n+y][y] = B[n+y][n+y] = 1;
	}
	B = pow(B, k+1);
	for (int y=0; y<n; ++y) {
		for (int x=0; x<n; ++x) {
			int a = B[n+y][x] % M;
			if (y==x) a = (a+M-1)%M;
			printf("%d%c",a,x+1==n?'\n':' ');
		}
	}
}

int
main()
{
	scanf("%d %d %d",&n,&k,&M);
	for (int y=0; y<n; ++y) {
		for (int x=0; x<n; ++x) {
			scanf("%d",&A[y][x]);
		}
	}
	solve();
}