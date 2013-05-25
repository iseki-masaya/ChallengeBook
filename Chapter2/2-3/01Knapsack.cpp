#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Knapsack {
public:
	int W[10001];
//	int W[10001] = {0}; //初期化すると、インスタンス変数として扱われる。
//	vector<int> W;      //vectorで定義すると、上と同様にインスタンス変数として扱われる。
public:
	Knapsack()
	{
		W[0] = 0;
	}
	int getMaxValue(vector<int> weight,vector<int> value,int capacity)
	{
//		W.resize(10001);
		for (int i=0; i<weight.size(); ++i) {

			for (int j=capacity; j>=0; --j)
				if (W[j] != 0 && j+weight.at(i)<=capacity)
					W[j+weight.at(i)] = max(W[j+weight.at(i)],W[j]+value.at(i));

			W[weight.at(i)] = max(value.at(i),W[weight.at(i)]);
		}
		int ans = 0;
		for (int i=0; i<=capacity; ++i)
			ans = max(ans,W[i]);

		return ans;
	}
};

#include <assert.h>

void test1 ()
{
	unique_ptr<Knapsack> k(new Knapsack);
	vector<int> weight = {2,1,3,2};
	vector<int> value = {3,2,4,2};
	assert( k->getMaxValue(weight, value, 5) == 7);
}

void test2 ()
{
	unique_ptr<Knapsack> k(new Knapsack);

	cout << k->W[5] << endl;

	vector<int> weight = {1,3,2,6,4};
	vector<int> value = {2,5,9,3,2};
	assert( k->getMaxValue(weight, value, 11) == 18);
}

int main(){
	test1();
	test2();
	cout << "OK" << endl;
}