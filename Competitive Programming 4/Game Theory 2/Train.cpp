/*
1 tàu n toa 1 -> n;
*/

#include<bits/stdc++.h>
using namespace std;

int dist(int a, int b, int direction, int n) {
  if (direction == -1) {
    if (a <= b) {
      return b - a;
    } else {
      return a + b - 2;
    }
  } else {
    if (a >= b) {
      return a - b;
    } else {
      return 2 * n - 2 - a - b;
    }
  }
}

int main(){
  int n, m, k, d;
  cin >> n >> m >> k;
  string s;
  cin >> s; 
  cin >> s;
  if (s[0] == 't') d = 1;
  else d = -1;
  cin >> s;
  int len = s.length();
  
  for (int i = 0; i < len; i++){
    // cout << k <<' '<<m << endl;
    int temp = k;
    k += d;
    if (k == 1 || k == n) d = -d;
    int bestPosition = k;
    if (s[i] == '0') {
      for (int dir = -1; dir <= 1; dir++) {
        int tempM = m + dir;
        if (tempM == temp) {
          continue;
        }
        if (tempM < 1 || tempM > n) continue;
        
        if (dist(bestPosition, k, d, n) < dist(tempM, k, d, n)) {
          bestPosition = tempM;
        }
      }
      if (bestPosition == k) {
        cout << "Controller " << i + 1 << endl;
        return 0;
      }
    } else {
      if (dist(bestPosition, k, d, n) < dist(1, k, d, n)) {
        bestPosition = 1;
      }
      if (dist(bestPosition, k, d, n) < dist(n, k, d, n)) {
        bestPosition = n;
      }
      
    }
    m = bestPosition;
    
  }  
  cout << "Stowaway";
}