#include<bits/stdc++.h>
using namespace std;

int len[15] = {3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3};
int moves[15][5] = {
  {1, 2, 3}, 
  {4, 5, 6, 7}, 
  {8, 9, 10, 11, 12}, 
  {13, 14, 15, 16}, 
  {17, 18, 19},
  {1, 4, 8}, 
  {2, 5, 9, 13}, 
  {3, 6, 10, 14, 17}, 
  {7, 11, 15, 18}, 
  {12, 16, 19},
  {8, 13, 17}, 
  {4, 9, 14, 18}, 
  {1, 5, 10, 15, 19}, 
  {2, 6, 11, 16}, 
  {3, 7, 12},
};
int dp[1 << 20];

bool f(int mask){
  if (dp[mask] != -1){
    return dp[mask];
  }
  
  for (int n = 0; n < 15; n++){
    for (int i = 0; i < len[n]; i++){
      for(int j = i; j < len[n]; j++){
        int pmask = mask;
        bool cont = true;
        for (int k = i; cont && k <= j; k++){
          if (mask & (1 << moves[n][k])){
            pmask -= (1 << moves[n][k]);
          }
          else {
            cont = false;
          }
        }
        if (cont){
            f(pmask);
            if (dp[pmask] == false){
              return dp[mask] = true;
            }
        }
        else break;
      }
    }
  }
  return dp[mask] = false;
}

int main(){
  int mask = 0;
  for (int i = 1; i <= 19; i++){
    char c;
    cin >> c;
    if (c == 'O'){
      mask += (1 << i);
    }
  }
  memset(dp, -1, sizeof(dp));  
  dp[0] = 0;
  f(mask);
  if (dp[mask] == 0){
    cout << "Lillebror";
  }
  else cout << "Karlsson";
}