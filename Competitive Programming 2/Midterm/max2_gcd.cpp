// Time O(n * m);

#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int solve(){
    for (int i = 1e5; i >= 1; i--){
        for (int j = 0; j < a.size(); j++){
            if (a[j] % i == 0){
                cnt[i]++;
                if (cnt[i] == 2){
                    return i;
                }
            }
        }
    }
    return 1;
}

int main(){
    int tt;
    cin >> tt;
    getchar();
    while (tt--){
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
        // for (int ai : a) cout << ai << " ";
        // cout << endl;
        memset(cnt, 0, sizeof(cnt));
        cout << solve() << endl;
        a.clear();
    }
    return 0;
}