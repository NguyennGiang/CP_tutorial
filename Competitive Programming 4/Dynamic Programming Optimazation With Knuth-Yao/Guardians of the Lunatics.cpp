/*
  f[i][j] = f[i][k] + f[k+1][j] + (j - i + 1) * (sum[x]) (i <= x <= j)
  
  f[g][l] = là rủi ro nhỏ nhất nếu em phân l người đầu tiên cho g bảo vệ quản lý
  f[g][l] = f[g-1][k] + cost(k+1, l)
  cost(i, j) = chi phí để 1 bảo vệ canh chừng nhóm người từ i -> j
  ban đầu có 1 ông -> f[1][l] = sum(1 -> l) * l
  f[2][l] = f[1][k] + sum(k + 1, l) * (l - k);
  
  f[i][j] = f[i][k] + f[k+1][j] + w(i,j);
  
  answer = f[G][L]
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 8000 + 5;
int G, L;
long long a[N];
long long sum[N], f[N][N], p[N][N];

int main(){
  cin >> L >> G;
  for (int i = 1; i <= L; i++){
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }
  
  for (int i = 1; i <= L; i++) {
    f[1][i] = 1LL * sum[i] * i; 
    p[1][i] = 0;
    p[G+1][i] = i-1;
  }
  
  for (int l = 1; l <= L; l++){
    for (int g = G; g >= 2; g--){
      f[g][l] = 1e18;
      for (int k = p[g][l-1]; k <= min(1LL * l, p[g+1][l]); k++){
        long long tmp = f[g-1][k] + (sum[l] - sum[k]) * (l - k);
        if (f[g][l] > tmp){
          f[g][l] = tmp;
          p[g][l] = k;
        }
      }
    }
  }
  cout << f[G][L];
  return 0;
}