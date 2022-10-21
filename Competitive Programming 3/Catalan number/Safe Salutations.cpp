#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  long long c[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 
                  16796, 58786, 208012, 742900, 2674440, 9694845, 
                  35357670, 129644790, 477638700, 1767263190};
  while(cin >> n){
    for (int i = 1; i <= 19; i++){
      if (c[i] == n){
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}