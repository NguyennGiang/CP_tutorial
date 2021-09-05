#include <bits/stdc++.h>

using namespace std;

int main(){
  int q; 
  cin >> q;
  queue <pair<int, int>> school[4]; // hàng của 4 lớp 
  queue <int> p; // thứ tự ghi danh của các trường
  for (int i = 0; i < q; i++) {
    char x; 
    cin >> x; 
    if (x == 'E'){
      pair <int, int> student; 
      cin >> student.first >> student.second;
      if (school[student.first - 1].empty()) {
        p.push(student.first - 1);     // ghi danh vào bẳn số tự tự của từng lớp 
      }
      school[student.first - 1].push(student);
    }
    if (x == 'D'){
      cout << school[p.front()].front().first << " " << school[p.front()].front().second << endl;
      school[p.front()].pop();
      if (school[p.front()].empty()) {
        p.pop();       // khi hết học sinh lớp đươc ghi danh đầu tiên, chuyển sang lớp ghi danh tiếp theo 
      }
    } 
  }
  return 0; 
} 