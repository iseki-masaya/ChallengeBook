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
solve(vector<int> &A)
{
	for (int i=0; i <= (1<<10)-1; ++i) {
		int prevB=-1,prevC=-1;
		bool isOk = true;
		for (int j=0; j<10; ++j) {
			if ( ((i>>j)&1) == 1 ) {
				if (prevB >= A[j]) {
					isOk = false;
					break;
				}
				prevB = A[j];
			}
			else {
				if (prevC >= A[j]) {
					isOk = false;
					break;
				}
				prevC = A[j];
			}
		}
		if (isOk) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
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
