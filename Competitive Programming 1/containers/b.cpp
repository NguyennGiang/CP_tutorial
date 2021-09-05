#include <bits/stdc++.h>

using namespace std; 

int main() {
  int t; 
  cin >> t; 
  for (int i = 0; i < t; i++){
    int n;
    cin >> n; 
    getchar();
    vector <string> direc;
    for (int j = 0; j < n; j++){
      string s; 
      getline(cin, s); 
      if (s == "pwd"){
        cout << "/";
        for (int  m = 0; m < direc.size(); m++ ){
          cout << direc[m] << "/";
        } 
        cout << '\n';
      }
      else {
        s += '/';
        string h; 
        int start = 3;
        if (s[3] == '/') {
          direc.clear();
          start = 4;
        }
        for (int k = start; k < s.size(); k++) { 
          if (s[k] != '/') {
            h += s[k];
          }
          else {
            if (h == "..") {
              if (direc.size() != 0){
                direc.pop_back();
              } 
            }
            else {
              direc.push_back(h);
            }
            h = "";
          }
        }
      }
    }
  }
  return 0;
}