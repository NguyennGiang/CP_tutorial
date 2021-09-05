#include <bits/stdc++.h>
using namespace std; 

int main() {
  int t; 
  cin >> t; 
  while(t--){
    long long l, r; 
    cin >> l >> r; 
    long long k = 0;
    
    while((l | (1LL << k)) <= r){
      l = l | (1LL << k);
      k++;
    }
    cout << l << endl; 
  }
  return 0;
}
