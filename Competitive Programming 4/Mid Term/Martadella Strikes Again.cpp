#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long a, b;
    cin >> a >> b;
    long long check = a * a - 2 * b * b;
    // cout << check << endl;
    cout << (check > 1? "1" : "2") << endl;
  }
  return 0;
}