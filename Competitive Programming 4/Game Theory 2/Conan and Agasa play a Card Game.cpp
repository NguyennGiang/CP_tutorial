#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    a[x]++;
  }
  
  for (int i = 0; i <= 100000; i++){
    if (a[i] % 2){
      cout << "Conan";
      return 0;
    }
  }
  cout << "Agasa";
}