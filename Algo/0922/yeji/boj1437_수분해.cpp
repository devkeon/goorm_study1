#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m = 10007;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  int three=1;
  int ans = 0;

  while(n>5){
    three*=3;
    three%=m;
    n-=3;
  }

  ans = three * n % m;
  
  

  cout << ans << '\n';
}