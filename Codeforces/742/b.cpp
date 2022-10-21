#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        int aa = a - 1;
        int ans;
        if (aa % 4 == 1){
            ans = 1;
        }
        if (aa % 4 == 2){
            ans = aa + 1;
        }
        if (aa % 4 == 3){
            ans = 0;
        }
        if (aa % 4 == 0){
            ans = aa;
        }
        int x = ans ^ b;
        if (ans == b){
            cout << a;
        }
        else if (x == a){
            cout << a + 2;
        }
        else {
            cout << a + 1;
        }
        cout << endl;
    }
    return 0;
}