#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

#define MAX 20001

int main(){
	int N,tmp;
	cin >> N;
	int L[MAX+1];
	for (int i=0; i<N; ++i) {
		cin >> tmp;
		L[i] = tmp;
	}

	long long cost = 0;

	int mni1=0,mni2=1;
	while (N > 1) {
		mni1=0,mni2=1;
		if (L[mni1] > L[mni2]) {
			swap(mni1, mni2);
		}

		for (int i=2; i<N; ++i) {
			if (L[mni1] > L[i]) {
				mni2 = mni1;
				mni1 = i;
			}
			else if (L[mni2] > L[i]) {
				mni2 = i;
			}
		}

		cost += L[mni1] + L[mni2];
		if (mni1 == N-1) {
			L[mni2] = L[mni1] + L[mni2];
		}
		else if (mni2 == N-1) {
			L[mni1] = L[mni1] + L[mni2];
		}
		else {
			L[mni1] = L[mni1] + L[mni2];
			L[mni2] = L[N-1];
		}
		--N;
	}

	cout << cost << endl;
	return 0;
}