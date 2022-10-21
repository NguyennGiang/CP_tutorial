#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int n;
int x[N], y[N];

int main(){
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  
  long long res = 0;
  int cnt = 0;
  map<pair<int, int>, set<int>> mp;
  
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int x1 = x[i], y1 = y[i];
      int x2 = x[j], y2 = y[j];
      
      int a = y2 - y1, b = x1 - x2;
      int c = -(a * x1 + b * y1);
      int f = __gcd(a, b);
      a /= f, b /= f, c /= f;
      if (a < 0) a = -a, b = -b, c = -c;
      pair<int, int> g = {a, b};
      
      if (mp[g].find(c) == mp[g].end()){
        cnt ++;
        mp[g].insert(c);
        res += cnt - mp[g].size();
      } 
    }
  }
  cout << res << endl;
  return 0;
}