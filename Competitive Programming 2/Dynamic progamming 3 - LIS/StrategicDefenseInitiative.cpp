#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  getchar();
  string ch;
  getline(cin, ch);
  while (t--){
    vector <int> nums;
    vector <int> dp;
    vector <int> pre;
    while(getline(cin, ch) && ch.length()){
      int num = stoi(ch);
      nums.push_back(num);
    } 
    int n = nums.size();
    dp.assign(n, 1);
    pre.assign(n, -1);
    int res = 0;
    for (int i = 1; i < n; i++){
      for (int j = 0; j < i; j++){
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
          dp[i] = dp[j] + 1;
          pre[i] = j;
        }
      }
      if (dp[res] < dp[i]){
        res = i;
      }
    }
    cout << "Max hits: " << dp[res] << '\n';
    vector <int> trace;
    while(res != -1){
      trace.push_back(nums[res]);
      res = pre[res];
    }
    for (int i = trace.size() - 1; i >= 0; i--){
      cout << trace[i] << '\n';
    }
    cout << '\n';
  }
  return 0;
}