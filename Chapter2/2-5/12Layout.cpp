#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

#define MAX_ML 10001
#define MAX_MD 10001
#define MAX_N 1001
#define INF (1<<30)

int N,ML,MD;
int AL[MAX_ML],BL[MAX_ML],DL[MAX_ML];
int AD[MAX_MD],BD[MAX_MD],DD[MAX_MD];

int d[MAX_N];

int solve()
{
	fill(d, d+N, INF);
	d[0] = 0;

	for (int k=0; k<N; ++k) {
		for (int i=0; i+1<N; ++i) {
			if (d[i+1]<INF) {
				d[i] = min(d[i],d[i+1]);
			}
		}

		for (int i=0; i<ML; ++i) {
			if (d[AL[i]-1]<INF) {
				d[BL[i]-1] = min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
			}
		}

		for (int i=0; i<MD; ++i) {
			if (d[BD[i]-1] < INF) {
				d[AD[i]-1] = min(d[AD[i]-1],d[BD[i]-1] - DD[i]);
			}
		}
	}

	int res = d[N-1];
	if (d[0]<0) {
		res=-1;
	}
	else if(res==INF) {
		res = -2;
	}

	return res;
}

int main()
{
	scanf("%d %d %d",&N,&ML,&MD);
	for (int i=0; i<ML; ++i) {
		scanf("%d %d %d",&AL[i],&BL[i],&DL[i]);
	}
	for (int i=0; i<MD; ++i) {
		scanf("%d %d %d",&AD[i],&BD[i],&DD[i]);
	}

	printf("%d",solve());
}
