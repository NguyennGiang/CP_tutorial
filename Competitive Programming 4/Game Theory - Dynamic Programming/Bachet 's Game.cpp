#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    int m; cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    
    vector<bool> f(n + 1, false);
    for (int i = 1; i <= n; i++){
      for (int mv : a){
        if (mv <= i && f[i-mv] == false){
          f[i] = true;
        }
      }
    }
    
    if (f[n] == true){
      cout << "Stan wins\n";
    }
    else {
      cout << "Ollie wins\n";
    }
  }
}