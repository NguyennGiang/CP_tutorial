#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        string res = "";
        for (int i = 0; i < n; i++){
            if (s[i] == 'D') res += "U";
            else if (s[i] == 'U') res += "D";
            else if (s[i] == 'L') res += "L";
            else res += "R";
        }
        cout << res << endl;
    }
    return 0;
}