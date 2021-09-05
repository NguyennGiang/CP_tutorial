#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool isFib[1000000]; //1e6;
  memset(isFib, false, sizeof(isFib));
  int a = 0;
  int b = 1;
  int res;
  for (int i = 2; res < 1e6; i++){
    res = a + b;
    a = b;
    b = res;
    if (res < 1e6){
       isFib[res] = true;
    }
  }
  int id = 0;
  while(1){
    if (!isFib[id]){
      n--;
    }
    if (n < 0){
      cout << id;
      break;
    }
    id++;
  }
  return 0;
}