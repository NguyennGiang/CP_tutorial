
#include <bits/stdc++.h>
using namespace std; 

int main (){
  int t; 
  cin >> t; 
  getchar();
  while(t--){
    string s; 
    cin >> s; 
    int point = 0;
    for (int i = 0; i < s.size(); i++){
      vector <int> f(26, 0);
      int ans = 0;
      for (int j = i; j < s.size(); j++){
        if (f[s[j] - 97] == 1) break;
        else {
          f[s[j] - 97] = 1;
          ans++;
        }
      }
      point = max(point, ans);
    } 
    cout << point << endl;
  }
  return 0;
}