#include <bits/stdc++.h>

using namespace std; 

int main() {
    int q;
    cin >> q; 
    stack <int> book;
    for (int i = 0; i < q; i++) {
        int x; 
        cin >> x; 
        if (x == 1){
        int y; 
        cin >> y; 
        book.push(y);
        }
        else{
            if (book.empty()) cout << "kuchbhi?\n";
            else {
                cout << book.top() << "\n";
                book.pop();
            }
        }
  }
  return 0;
}