#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string& t){
  int n = t.size();
  vector<int> p(n);
  int l = 0, r = -1;
  for (int i = 0; i < n; i++){
    int k = i > r ? 0 : min(p[l + r - i], r - i);
    while(0 <= i - k - 1 && i + k + 1 < n && t[i - k - 1] == t[i + k + 1]) k ++;
    p[i] = k;
    if (i + k > r){
      l = i - k;
      r = i + k;
    }
  }
  return p;
}

int main(){
  
  int t; cin >> t;
  while(t--){
    string s;
    cin >> s;
    string t(2 * s.length() + 1, '#');
    for (int i = 0; i < s.length(); i++){
      t[2 * i + 1] = s[i];
    }
    vector<int> p = manacher(t);
    
    int res[2];
    res[0] = res[1] = 0;
    for (int i = 0; i < p.size(); i++){
      if (p[i] > res[0]){
        res[0] = p[i];
        res[1] = 1;
      }
      else if (p[i] ==  res[0]) res[1]++;
    }
    cout << res[0] << ' ' << res[1] << endl;
  }
  return 0;
}





