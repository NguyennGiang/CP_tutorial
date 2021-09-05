#include <bits/stdc++.h>

using namespace std;
int parent[256];

int find(int s){
  if(s != parent[s]){
    parent[s] = find(parent[s]);
  }
  return parent[s];
}

void make(){
  for (int i = 0; i < 256; i++){
    parent[i] = i;
  }
}

void unionSet(int u, int v){
  int pv = find(v);
  int pu = find(u);
  if (pu == pv){
    return;
  }
  else{
    if (pv > pu){
      parent[pv] = pu;
    }
    else parent[pu] = pv;
  }
}

int main(){
  string a, b, c;
  cin >> a >> b >> c;
  make();
  
  for (int i = 0; i < a.size(); i++){
    unionSet(int(a[i]), int(b[i]));
  }    
  
  for (int i = 0; i < c.size(); i++){
    cout << char(find(int(c[i])));
  }
  cout << endl;
  return 0;
}