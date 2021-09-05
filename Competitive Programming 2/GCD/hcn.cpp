#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

// int gcd(int a, int b){
//   if (b == 0){
//     return a;
//   }
//   return gcd(b, a % b);
// }

int main(){
  int n;
  cin >> n;
  vector <int> a(n);
  vector <int> b(n);
  vector <pair <int, int>> res;
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    if (a[i] > b[i]) swap(a[i], b[i]);
    int x = __gcd(a[i], b[i]);
    a[i] = a[i] / x;
    b[i] = b[i] / x;
    res.push_back({a[i], b[i]});
   // cout << a[i] << ' '<< b[i] << endl;
  }
  sort(res.begin(), res.end());
  int group = 1;
  int countMember = 0; // so luong hcn 
  int cnt = 1;
  //pair <int, int> pre = res[0];
  for (int i = 1; i < n; i++){
    if (res[i] == res[i-1]){
      cerr << "i am here\n";
      cnt++;
    }
    else {
      cerr << "here 2\n";
      //countMember = max(countMember, cnt);
      cnt = 1;
     // pre = res[i];
      group++;
    }
    countMember = max(countMember, cnt);
  }
  cout << group << " " << countMember;
  return 0;
}

