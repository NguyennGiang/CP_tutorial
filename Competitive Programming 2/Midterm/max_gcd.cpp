#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int tt;
    cin >> tt;
    getchar();
    while (tt--){
        vector <int> a;
        string s;
        getline(cin, s);
        int tmp = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                tmp = tmp * 10 + s[i] - '0';
            }
            else {
                a.push_back(tmp);
                tmp = 0;
                if (s[i] == '\0'){
                    break;
                }
            }
        }
        if (tmp != 0){
            a.push_back(tmp);
        }
        int res = 0;
        for (int i = 0; i < a.size(); i++){
            for (int j = i + 1; j < a.size(); j++){
                int cur = gcd(a[i], a[j]);
                res = max(res, cur);
            }
        }
        cout << res << endl;
    }
    return 0;
}