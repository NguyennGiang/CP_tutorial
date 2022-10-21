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
  
  string s;
  cin >> s;
  
  string t(2 * s.length() + 1, '#');
  for (int i = 0; i < s.length(); i++){
    t[2 * i + 1] = s[i];
  }
  vector<int> p = manacher(t);
  
  int res = 0;
  for (int x : p) res += (x + 1) / 2;
  cout << res << endl;
  return 0;
}





