#include <bits/stdc++.h>

using namespace std; 

int convert(string &a) {
  return int(a[0] - 48) * 10 * 60 + int(a[1] - 48) * 60 + int(a[3] - 48) * 10 + int(a[4] - 48);
}

int main() {
  int t;
  cin >> t; 
  for (int tc = 1; tc <=t; tc++){
    int n; 
    cin >> n; 
    int na, nb; 
    cin >> na >> nb;
    priority_queue <int, vector<int>, greater<int> > tripsA;
    priority_queue <int, vector<int>, greater<int> > tripsB;
    vector <int> As; 
    vector <int> Bs;
    for (int i = 0; i < na; i++) {
      string a, b; 
      cin >> a >> b; 
      As.push_back(convert(a));
      tripsA.push(convert(b) + n);
    }
    for (int i = 0; i < nb; i++){
      string a, b; 
      cin >> a >> b; 
      Bs.push_back(convert(a));
      tripsB.push(convert(b) + n);
    }
    sort(As.begin(), As.end()); 
    sort(Bs.begin(), Bs.end());
    for (int i = 0; i<Bs.size(); i++) {
      if (!tripsA.empty() && tripsA.top() <= Bs[i]) {
        nb--;
        tripsA.pop();
      }
    }
    for (int i = 0; i < As.size(); i++){
      if (!tripsB.empty() && tripsB.top() <= As[i]) {
        na--; 
        tripsB.pop();
      }
    }
    cout << "Case #" << tc << ": "; 
    cout << na << " " << nb << endl;  
  }
  return 0;
}