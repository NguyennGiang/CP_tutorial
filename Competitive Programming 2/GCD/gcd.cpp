#include <iostream>
using namespace std;

int gcd(int i, int j){
  if (j == 0){
    return i;
  }
  return gcd(j, i % j);
}

int main(){
  int n;
  while(1){
    cin >> n;
    if (!n){
      break;
    }
    int ans = 0;
    for (int i = 1; i < n; i++){
      for (int j = i + 1; j <= n; j++){
        ans += gcd(i, j);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}