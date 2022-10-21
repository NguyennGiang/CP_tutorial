#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int sum[N], cnt[N][3];

string modify(string& s){
  string t = "";
  for (int i = 0; i < s.size(); i ++){
    t += "#";
    t += s[i];
  }
  return t + "#";
}

int get(int l, int r, int y){
  if (l > r) return 0;
  if (l > 0){
    int t = (sum[l-1] + y) % 3;
    return cnt[r][t] - cnt[l-1][t];
  }
  return cnt[r][y];
}

long long manacher(string& s){
  long long ans = 0;
  int n = s.size();
  vector<int> p(n);
  int l = 0, r = -1;
  for (int i = 0; i < n; i++){
    int k = i > r ? 0 : min(p[l + r - i], r - i);
    while(0 <= i - k - 1 && i + k + 1 < n && s[i - k - 1] == s[i + k + 1]) k ++;
    p[i] = k;
    if (i + k > r){
      l = i - k;
      r = i + k;
    }
    
    if (s[i] != '#'){
      ans += get(i + 1, i + k, (s[i] - '0') % 3);
      if ((s[i] - '0') % 3 == 0) ans++;
    }
    else {
      ans += get(i + 1, i + k, 0);
    }
  }
  return ans;
}

int main(){
  string s; cin >> s;
  s = modify(s);
  
  int n = s.length();
  
  for (int i = 1; i < n; i++){
    sum[i] = sum[i-1];
    if (s[i] != '#'){
      sum[i] += s[i] - '0';
      sum[i] %= 3;
    }
    for (int j = 0; j < 3; j++){
      cnt[i][j] = cnt[i-1][j];
    }
    if (s[i] != '#' && s[i] != '0'){
      cnt[i][sum[i]]++;
    }
  }
  
  long long ans = manacher(s);
  cout << ans << endl;
  return 0;
}