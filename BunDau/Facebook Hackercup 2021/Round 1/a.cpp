#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n;
        string s;
        cin >> n >> s;
        int change = 0;
        int pre = '.';
        for (char ch : s){
            if (ch == 'X' || ch == 'O'){
                if (pre == ch || pre == '.'){
                    pre = ch;
                    continue;
                }
                change ++;
                pre = ch;
            }
        }
        cout << "Case #" << tc << ": " << change << endl;
    }
    return 0;
}