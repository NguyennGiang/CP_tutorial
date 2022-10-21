#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
map<pair<int, int>, bool> mp;
int a[2 * N + 5];
vector<int> manacher(int n){
  vector<int> p(2 * n + 1);
  int l = 0, r = -1;
  for (int i = 0; i < p.size(); i++){
    int k = i > r ? 0 : min(p[l + r - i], r - i);
    while(0 <= i - k - 1 && i + k + 1 < p.size() && mp[{a[i-k-1], a[i+k+1]}]) k ++;
    p[i] = k;
    if (i + k > r){
      l = i - k;
      r = i + k;
    }
  }
  return p;
}

int main(){
  
  int n, m;
  cin >> n >> m;
  while(m--){
    int a, b;
    cin >> a >> b;
    mp[{a, b}] = true;
    mp[{b, a}] = true;
  }
  mp[{0, 0}] = true;
  for (int i = 1; i < 2 * n; i += 2){
    a[i] = (i + 1) / 2;
  }
  
  vector<int> p = manacher(n);
  cout << *max_element(p.begin(), p.end());
  return 0;
}





