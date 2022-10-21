#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k;
  cin >> n >> m;
  cin >> k;
  int win = 0;
  for (int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;
    
    if (x <= 5 || (n - x + 1) <= 5 ){
      win = 1;
    }
    
    if (y <= 5 || (m - y + 1) <= 5){
      win = 1;
    }
  }
  
  if (win){
    cout << "YES";
  }
  else cout << "NO";
}