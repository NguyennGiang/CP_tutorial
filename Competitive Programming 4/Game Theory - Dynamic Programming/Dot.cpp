#include<bits/stdc++.h>
using namespace std;

const int N = 25;
int x, y, n, d;
int dx[N], dy[N];
int dp[500][500];

int dist(int x, int y){
  return x * x + y * y > d * d;
}

int f(int x, int y){
  if (dist(x - 210, y - 210)){
    return 1;
  }
  if (dp[x][y] == -1){
    dp[x][y] = 0;
    for (int i = 0; i < n; i++){
      if (!f(x + dx[i], y + dy[i])){
        return dp[x][y] = 1;
      }
    }
  }
  return dp[x][y];
}

int main(){
  cin >> x >> y >> n >> d;
  for (int i = 0; i < n; i++){
    cin >> dx[i] >> dy[i];
  }  
  
  memset(dp, -1, sizeof(dp));
  bool flag = f(x + 210, y + 210);
  if(flag){
    cout << "Anton";
  }
  else {
    cout << "Dasha";
  }
}