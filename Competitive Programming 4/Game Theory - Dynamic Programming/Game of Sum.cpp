#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N];
int sum[N];
int n;

int f(int i, int j){
  if (dp[i][j] != -1){
    return dp[i][j];
  }
  
  int m = 0;
  for (int k = i + 1; k <= j; k++) m = min(m, f(k, j));
  for (int k = i; k < j; k++) m = min(m, f(i, k));
  
  return dp[i][j] = sum[j] - sum[i-1] - m;
}

int main(){
  while(cin >> n && n){
    for (int i = 1; i <= n; i++){
      int x;
      cin >> x;
      sum[i] = sum[i-1] + x;
    }
    
    memset(dp, -1, sizeof(dp));
    int playA = f(1, n);
    cout << playA - (sum[n] - playA) << endl;
  }
}