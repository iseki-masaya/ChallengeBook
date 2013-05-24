#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n,c=0;
  char a;
  string S = "";
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    S += a;
  }

  int l = 0, r = n-1;
  bool left;
  while(l <= r){
    c++;
    left = false;
    for(int i = 0; i <= r-l; i++){
      if(S[l + i] < S[r - i]){
				left = true;
				break;
      }else if(S[l + i] > S[r - i]){
				left = false;
				break;
      }
    }
    if(left) putchar(S[l++]);
    else putchar(S[r--]);
    if(c==80){
      putchar('\n');
      c = 0;
    }
  }
  putchar('\n');
}