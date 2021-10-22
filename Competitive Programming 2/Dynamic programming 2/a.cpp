#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
string a, b;
int dp[N][N];

int solve(int i, int j){
  if (i == a.length() || j == b.length()){
    return 0;
  }
  if (dp[i][j] != -1) return dp[i][j];
  int res;
  if(a[i] == b[j]){
    res = solve(i + 1, j + 1) + 1;
  }
  else res = max(solve(i + 1, j), solve(i, j + 1));
  dp[i][j] = res;
  return dp[i][j];
}

int main(){
  cin >> a >> b;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0);
  return 0;
}