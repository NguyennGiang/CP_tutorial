#include<bits/stdc++.h>
using namespace std;

const int N = 255;
const int mod = 1e9 + 7;
const int base = 131;
int n, m, ans;
char a[N][N];
int cnt[2 * N][26];
int odd[2 * N];
long long hashh[2 * N];
int f[2 * N];

bool cmp(int a, int b){
  if (a < 0 || b > 2 * n)
    return false;
  if (odd[a] > 1 || odd[b] > 1) return 0;
  if (hashh[a] != hashh[b]) return 0;
  return 1;
}

int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }
  
  int p[30];
  p[0] = 1;
  for (int i = 1; i < 30; i++) p[i] = 1LL * p[i-1] * base % mod;
  
  //cnt đếm trên hàng
  for (int left = 1; left <= m; left++) {
    
    memset(cnt, 0, sizeof(cnt));
    memset(odd, 0, sizeof(odd));
    memset(hashh, 0, sizeof(hashh));
    
    for (int right = left; right <= m; right++) {
      // cố định được bờ biên trái và phải 
      for (int i = 1; i <= n; i ++){ // hang
        cnt[2 * i - 1][a[i][right] - 'a']++;
        if (cnt[2 * i - 1][a[i][right] - 'a'] & 1) odd[2*i-1]++;
        else odd[2*i-1]--;
        // hashh[i] hashh cái mảng cnt[i] -> cnt[][] --> hashh[]
        hashh[2 * i - 1] += p[a[i][right] - 'a'];
        hashh[2 * i - 1] %= mod;
        //hashh = cnt[a] * base^0 + cnt[b] * base^1 + ... + cnt[z] * base^25
      }
      
      memset(f, 0, sizeof(f));
      cnt[2*n + 1][0] = -1;
      int p = 0, q = 0;
      for (int i = 1; i <= 2 * n; i++){
        if (odd[i] > 1) continue;
        f[i] = q > i ? min(f[2 * p - i], q - i) : 1;
        while(cmp(i - f[i], i + f[i]) == 1) f[i]++;
        f[i]--;
        if(i + f[i] > q) p = i, q = i + f[i];
        ans += (f[i] + 1) / 2;
      }
    }
  }
  cout << ans << endl;
}