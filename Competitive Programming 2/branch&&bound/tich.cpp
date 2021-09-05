#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-7;
long long VT = 1, VP = 1;
bool finished = false;
void backtracking(int n, int k, int cnt, long long preVal){
  if (VT > VP)
    return; 
  if (cnt == k - 1){
    if (VT % (VP - VT) == 0) {
      finished = true;  
    }      
    return;
  }
  for (long long i = preVal; ; i++){
    long long l = VT;
    long long r = VP;
    for (int j = cnt + 1; j <= k; j++) {
      l *= (i + 1);
      r *= i;
    }
    if (l < r)
      break;
    VT *= (i + 1);
    VP *= i;
    backtracking(n, k, cnt + 1, i);
    VT /= (i + 1);
    VP /= i;
    if (finished) return;
  }
}


int main(){
  int n;
  cin >> n;
  int k = 1;
  VP = n;
  while(1){
    backtracking(n, k, 0, 1);
    if (finished) break;
    k++;
  }
  cout << k;
  return 0;
}

