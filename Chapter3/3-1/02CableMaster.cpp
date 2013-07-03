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

#define I_INF (1<<20)
#define F_INF 1e7
#define MAX 101

using namespace std;

int
calc(float length,vector<float>&cable)
{
	int ret = 0;
	for (int i=0; i<cable.size(); ++i) {
		ret += static_cast<int>(cable[i]/length);
	}
	return ret;
}

double
solve(int N,int K,vector<float>&cable)
{
	double left=0,right=F_INF;
	for (int i=0; i<100; ++i) {
		double mid = (left+right)/2.0;
		if (K > calc(mid,cable)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	return right;
}

int
main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	vector<float> cable(N);
	for (int i=0; i<N; ++i) {
		scanf("%f",&cable[i]);
	}
	double ans = solve(N,K,cable);
	printf("%.2f\n",floor(ans*100)/100);
}