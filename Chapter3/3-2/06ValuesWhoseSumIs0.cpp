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

void
solve(int n,vector<int> &A,vector<int> &B,vector<int> &C,vector<int> &D)
{
	vector<int> CD(n*n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			CD[i*n+j] = C[i]+D[j];
		}
	}
	sort(CD.begin(), CD.end());
	long long res = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			int ab = -(A[i]+B[j]);
			res += upper_bound(CD.begin(), CD.end(), ab) - lower_bound(CD.begin(), CD.end(), ab);
		}
	}

	printf("%lld\n",res);
}

int
main()
{
	int num;
	scanf("%d",&num);
	vector<int> A(num),B(num),C(num),D(num);
	for (int i=0; i<num; ++i) {
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}
	solve(num,A,B,C,D);
}