#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;

int cnt[maxn];

int main(){
  while (true) {
    int m, n; 
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    memset(cnt, 0, sizeof(cnt));
    bool overlap = false;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(overlap) continue;
        for(int j = a; j < b; j++){
            cnt[j]++;
            if (cnt[j] > 1) {
            overlap = true;
            break;
            }
        }
        }
        for (int i = 0; i < m; i++ ) {
        int a, b, c; 
        cin >> a >> b >> c;
        if (overlap) continue;
        while(a <= 1e6) {
            for(int j = a; j < min(b, int(1e6 + 1)) ; j++) {
            cnt[j]++;
            if (cnt[j] > 1) {
                overlap = true;
                break;
            }
            }
                a += c;
                b += c;
            if (overlap) break;
      }
    }
    if(overlap) cout << "CONFLICT\n";
    else cout << "NO CONFLICT\n";
  }
  return 0; 
}

