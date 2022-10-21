#include<bits/stdc++.h>
using namespace std;

string s, t;
int f[100][100];

int editDistance(string s, string t, int n, int m){
  for (int i = 0; i <= n; i++){
    f[i][0] = i;    
  }
  for (int i = 0; i <= m; i++){
    f[0][i] = i;
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (s[i-1] == t[j-1]){
        f[i][j] = f[i-1][j-1];
      }
      else {
        f[i][j] = min({f[i-1][j-1], f[i-1][j], f[i][j-1]}) + 1;
      }
    }
  }
  return f[n][m];
}

void trace(string s, string t, int n, int m){
  int id = 1;
  while(n > 0 && m > 0){
    if (s[n-1] == t[m - 1]){
      n--,m--;
    }
    else if (f[n-1][m-1] == f[n][m] - 1){
      cout << id++ << " Replace " << n << "," << t[m-1] << endl;
      n--, m--;
    }
    else if (f[n-1][m] == f[n][m] - 1){
      cout << id++ << " Delete " << n << endl;
      n--;
    }
    else {
      cout << id++ << " Insert " << n + 1 << "," << t[m-1] << endl;
      m--;
    }
  }
  
  while(n > 0) cout << id++ << " Delete " <<  n-- << endl;
  while(m > 0) cout << id++ << " Insert 1," << t[--m] << endl;
}

int main(){
  int tc = 0;
  while(getline(cin, s)){
    getline(cin, t);
    int n = s.length();
    int m = t.length();
    if (tc++) cout << endl;
    cout << editDistance(s, t, n, m) << endl;
    trace(s, t, n, m);
  }  
}