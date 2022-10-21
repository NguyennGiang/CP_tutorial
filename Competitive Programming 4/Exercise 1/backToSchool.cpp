#include<bits/stdc++.h>
using namespace std;

const int ESP = 1e-5;

double get(double a, double b, double c, double d){
  return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
  int t;
  cin >> t;
  int cs = 1;
  while(t--){
    cout << "Case " << cs++ << ": ";
    double a, b, r, c, d;
    cin >> a >> b >> r >> c >> d;
    double dis = get(a, b, c, d);
    
    if (abs(r - dis) <= ESP){
      cout << "OnCircle";
    }
    else if(dis < r){
      cout << "Inside";
    }
    else cout << "Outside";
    cout << '\n';
  }
  return 0;
}