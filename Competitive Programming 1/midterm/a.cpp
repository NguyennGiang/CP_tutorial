// triangle

#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n; 
    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    long long cnt1 = 0; 
    long long cnt2 = 0; 
    long long cnt3 = 0;
    
    
    
    for (long long i = 0; i < n - 2; i++){
        long long k1 = 2;
        for (long long j = i + 1; j < n; j++){  
            while (k1 < n && a[i] + a[j] > a[k1])
            {
                k1++;                
            }
            cnt1 += k1 - j - 1; 
        }
    }
    
    long long k2 = 0;
    long long i = 0;
    while(i < n) {
      long long j = i;
      while (j < n && a[i] == a[j]) {
        j++;
      }
      long long cnt = j - i;
      while (k2 < n && 2 * a[i] > a[k2]) {
        k2++;
      }
      cnt2 += (cnt* (cnt - 1) / 2) * (k2 - cnt);
      i = j; 
    }
    
    for (long long i = 0; i < n; i++){
      long long l = i + 1;
      long long r = i + 1;
      for (long long j = i + 1; j < n; j++){
        while (l < n && (a[i] * a[i] + a[j] * a[j]) >  a[l] * a[l]){
          l++;
        }
        if (l == n || (a[i] * a[i] + a[j] * a[j]) <  a[l] * a[l]) continue;
        r = l;
        while (r < n && (a[i] * a[i] + a[j] * a[j]) ==  a[r] * a[r]) {
          r++;
        }
        cnt3 += r - l;
      }
    }
    // a[l..r]
    cout << cnt1 <<' '<<cnt2 <<' '<<cnt3;
    return 0;
}
