#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int sum1 = 0, sum2 = 0;
  vector<int> a;
  for (int i = 0; i < n; i++){
    int k, x;
    cin >> k;
    for (int j = 1; j <= k / 2; j++){
      cin >> x;
      sum1 += x;
    }
    if (k&1){
      cin >> x;
      a.push_back(x);
    }
    for (int j = 1; j <= k / 2; j++){
      cin >> x;
      sum2 += x;
    }
  }
  
  sort(a.begin(), a.end(), [](int a, int b){return a > b;});
  
  for (int i = 0; i < a.size(); i++){
    if (i & 1){
      sum2 += a[i];
    }
    else sum1 += a[i];
  }
  cout << sum1 << ' ' << sum2;
}