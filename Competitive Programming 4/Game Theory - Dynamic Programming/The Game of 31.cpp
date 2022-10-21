#include<bits/stdc++.h>
using namespace std;

int num[6];
int dp[5][5][5][5][5][5];

bool f(int state){
  if (num[0] * 1 + num[1] * 2 + num[2] * 3 + num[3] * 4 + num[4] * 5 + num[5] * 6 > 31){
    return (1 - state);
  }
  
  if (dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] != -1){
    return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]];
  }
  
  int next = 1 - state;
  
  for (int i = 0; i < 6; i++){
    if (num[i] < 4){
      num[i] ++;
      if (f(next) == next){
        num[i]--;
        return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] = next;
      }
      num[i] --;
    }
  }
  return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]] = state;
}

int main(){
  string str;
  
  while(getline(cin, str)){
    int len = str.length();
    memset(num, 0, sizeof(num));
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < len; i++){
      num[str[i] - '1'] ++;
    }
    
    int state = len % 2; // state = 1 -> A win
    if (f(state)){
      cout << str << " A\n";
    }
    else cout << str << " B\n";
  }
}