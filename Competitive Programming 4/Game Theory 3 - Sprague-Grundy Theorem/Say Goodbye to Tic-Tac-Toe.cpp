#include<bits/stdc++.h>
using namespace std;

const int N = 105;
char str[N];
int dp[3][3][N];

int getnum(char c){
  if (c == 'X') return 1;
  return 2;
}

int mex(int s, int e, int l){
  if (dp[s][e][l] != -1) return dp[s][e][l];
  if (l == 0) return dp[s][e][l] = 0;
  
  bool vis[N];
  memset(vis, 0, sizeof(vis));
  
  for (int i = 1; i <= l; i++){
    for (int j = 1; j <= 2; j++){
      if (i == 1 && s == j) continue;
      if (i == l && e == j) continue;
      
      int t = mex(s, j, i - 1) ^ mex(j, e, l - i);
      vis[t] = true;
    }
  }
  
  for (int i = 0; ; i ++){
    if (!vis[i]) return dp[s][e][l] = i;
  }
} 

int main(){
  int t;
  cin >> t;
  while(t--){
    scanf("%s",str);
  memset(dp, -1, sizeof(dp));
    
    int len = strlen(str), s = 0, e = 0, l = 0, ans = 0, cnt = 0;
    
    for (int i = 0; i < len; i++){
      if (str[i] == '.'){
        l++;
      }
      else {
        e = getnum(str[i]);
        ans ^= mex(s, e, l);
        s = e, l = 0, cnt++;
      }
    }
    
    ans ^= mex(s, 0, l);
    if (cnt & 1){
      ans = (ans == 0 ? 1 : 0);
    }
    
    if (ans){
      printf("Possible.\n");
    }
    else printf("Impossible.\n");
  }
}