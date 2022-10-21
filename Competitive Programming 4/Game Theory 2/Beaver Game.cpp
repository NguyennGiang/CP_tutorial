#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0){
    cout << "Marsel";
  }
  else {
    int flag = 0;
    for (int i = 1; i * i <= m; i++){
      if (m % i == 0){
        if (i >= k && m / i > 1 || m / i > k && i > 1){
          flag = 1;
          cout << "Timur";
          break;
        }
      }
    }
    if (!flag){
      cout << "Marsel";
    }
  }
}