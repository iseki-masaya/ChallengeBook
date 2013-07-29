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

#define MAX_W 103
#define MAX_H 103

bool
dps(vector<int> &A,int apos,int B,int C)
{
	if (apos == 10) {
		return true;
	}

	int d = A[apos];
	if (d > B) {
		swap(d, B);
		if(dps(A, apos+1, B, C))
			return true;
		swap(d, B);
	}
	if (d > C) {
		swap(d, C);
		if(dps(A, apos+1, B, C))
			return true;
		swap(d, C);
	}

	return false;
}

void
solve(vector<int> &A)
{
	if (dps(A,0,0,0)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	for (int i=0; i<num; ++i) {
		vector<int> A(10);
		for (int j=0; j<10; ++j) {
			scanf("%d",&A[j]);
		}
		solve(A);
	}
}
