/*
  với mỗi đoạn từ 1 - > i
  chia thành 2 đoạn từ 1 - > j -> i;
  dp[i] = min (dp[i], dp[j-1] + (a - b)^2 + c)
                      dp[j] + a ^ 2 + b ^ 2 - 2ab + c;
                      với a = x[i], b = x[j];
                      mỗi i tìm j nhỏ nhất sao cho dp[j] + a ^ 2 + b ^ 2 - 2ab + c nhỏ nhất
                      dp[j-1] + b^2 - 2ab  nhỏ nhất 
                      --> y = mx + n
                      x = a;
                      m = -2b; 
                      n = d[j] + x[j]^2
                      (a, b)
                      
                      x = x[i]
                      --> tìm ra min(ax + b)
                      
                      (l1, l2) -> (b1-b2)/(m2-m1);
                      (l1, l3) -> (b1 - b3)/(m3 - m1);
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
long long x[N];
long long dp[N];
vector <long long> M;
vector <long long> B;
int n, c;

bool check(int l1, int l2, int l3){
  return (B[l3] - B[l1]) * (M[l1] - M[l2]) < (B[l2] - B[l1]) * (M[l2] - M[l3]);
}

void add(long long m, long long b){
  M.push_back(m);
  B.push_back(b);
  
  while(M.size() >= 3 && check(M.size() - 3, M.size() - 2, M.size() - 1)){
    M.erase(M.end() - 2);
    B.erase(B.end() - 2);
  }
}

int p = 0;
long long query(long long x){
  int l = 0, r = M.size() - 1;
  long long res = B[r] + M[r] * x;
  while(l < r){
    int m = (l + r) / 2;
    if ((B[m+1] - B[m]) / (M[m] - M[m+1]) >= 1.0 * x){
      r = m;
      res = M[m] * x + B[m];
    } 
    else l = m + 1;
  }
  return res;
}

int main(){
  cin >> n >> c;
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }

  long long cost = 0;
  for (int i = 0; i < n; i++){
    add(-2 * x[i], cost + x[i] * x[i]);
    cost = x[i] * x[i] + c + query(x[i]);
  }
  cout << cost;
}

