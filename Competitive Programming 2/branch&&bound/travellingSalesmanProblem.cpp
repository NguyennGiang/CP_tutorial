#include <bits/stdc++.h>

using namespace std;
int n;
int a[16][16];
bool visited[16];
int res = 1e9;

void backtracking(int sum, int i, int cnt){
  if (cnt < n - 1 && sum < res){
      for (int j = 1; j < n; j++){
        if (visited[j] == 0){
          visited[j] = 1;
          backtracking(sum + a[i][j], j, cnt + 1);
          visited[j] = 0;
        }
      }
  }
  else {
    res = min(res, sum + a[i][0]);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  backtracking(0, 0, 0);
  cout << res;
  return 0;
} 