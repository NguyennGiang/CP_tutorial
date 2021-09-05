#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int res = 0;
    bool d[10];
    d[1] = true;
    for (int i = 2; i <= 9; i++){
        int ans = 0;
        for (int j = 0; j < n; j++){
            ans = (ans * 10 + s[j] - '0') % i;
        }
        if (ans == 0){
            d[i] = true;
        }
        else {
            d[i] = false;
        }
    }

    for (int i = 0; i < n; i++){
        if (d[s[i] - '0']){
            res++;
        }
    }
    cout << res;
    return 0;
}