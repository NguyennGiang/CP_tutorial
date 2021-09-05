#include <bits/stdc++.h>
using namespace std;

bool add[25];
int digit[25];
int n, res;

bool solve(int i){
    if (i == n){
        int sum = 0;
        for (int j = 0; j < n; ){
            if (add[j] == 1){
                int ans = digit[j];
                int k;
                for (k = j + 1; k < n; k++){
                    if (add[k] == 1){
                        break;
                    }
                    else {
                        ans = ans * 10 + digit[k];
                    }
                }
                sum += ans;
                j = k;
            }
        }
        if (sum == res){
            return true;
        }
        else {
            return false;
        }
    }
    for (int j = 0; j <= 1; j++){
        add[i] = j;
        if (solve(i + 1)){
            return true;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s >> res;
        n = s.length();
        for (int i = 0; i < n; i++){
            digit[i] = s[i] - '0'; 
        }
        memset(add, false, sizeof(add));
        add[0] = 1;
        solve(1);
        for (int i = 0; i < n; i++){
            if (i && add[i] == 1){
                cout << "+" << digit[i];
            }
            else {
                cout << digit[i];
            }
        }
        cout << endl;
    }
    return 0;
}