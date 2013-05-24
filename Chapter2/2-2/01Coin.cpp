#include <string>
#include <iostream>
#include <vector>

//3 2 1 3 0 2 620

using namespace std;

class Coin
{
private:
public:
	int getMin(int c1,int c5,int c10,int c50,int c100,int c500,int A)
	{
		int n=A,cnt=0;
		int rest[6] = {c500,c100,c50,c10,c5,c1};
		int value[6] = {500,100,50,10,5,1};
		for (int i=0; i<6; ++i) {
			for (int j=0; j<rest[i]; ++j) {
				if (n >= value[i] && rest[i] > 0) {
					n -= value[i];
					++cnt;
				}
				else {
					break;
				}
			}
		}
		return cnt;
	}
};

int main()
{
	Coin c;
	int c500,c100,c50,c10,c5,c1,A;
	cin >> c1 >> c5 >> c10 >> c50 >> c100 >> c500 >> A;
	cout << c.getMin(c1, c5, c10, c50, c100, c500, A);
}