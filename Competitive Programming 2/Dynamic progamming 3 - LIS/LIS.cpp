#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  // vector <int> dp(n, 1);
  vector <int> lis;
  for (int i = 0; i < n; i++){
    int j = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
    if (j == lis.size()){
      lis.push_back(a[i]);
    }
    else {
      lis[j] = a[i];
    }
  }
  cout << lis.size() << endl;
  return 0;
}