#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <bitset>

using namespace std;

class PartialSum
{
public:
	bool isMake(vector<int> vec,int k)
	{
		int size = static_cast<int>(vec.size());
		int sum = 0;
		for (int i=1; i < 1<<size ; ++i) {
			sum = 0;
			for (int j=0; j<size; ++j) {
				if (((i>>j)&1) == 1) {
					sum += vec.at(j);
				}
			}
			if (sum == k) {
				return true;
			}
		}

		return false;
	}
};