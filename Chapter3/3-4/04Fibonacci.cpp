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

const int M = 10000;

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

long long n;

void
solve()
{
	mat A(2 , vec(2));
	A[0][0] = 1; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 0;
	A = pow(A, n);
	printf("%d\n",A[1][0]);
 }

int
main()
{
	scanf("%lld",&n);
	solve();
}