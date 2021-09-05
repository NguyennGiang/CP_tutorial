#include <bits/stdc++.h>
using namespace std; 

int result(long long n){
    if (n < 10){
        return n;
    }
    else return  result(result(n/10) + n % 10);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; 
    cin >> t; 
    for (int i = 0; i < t; i++){
        long long m, n; 
        cin >> n >> m; 
        long long a = 1;
        if (m >= 6){
          cout << 9 << endl;
        }
        else{
          for (long long i = 1; i <= m; i++){
              a *= result(n);
              n++;
          }
          cout << result(a) << endl;
        }
    }
    return 0;
}