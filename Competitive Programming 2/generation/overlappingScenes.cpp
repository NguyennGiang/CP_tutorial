#include <bits/stdc++.h>

using namespace std;

int n;
const int INF = 1e9;
string s[20];

int solve(){
    string ans = s[0];
    for (int i = 1; i < n; i++){
        int l = min (ans.size(), s[i].size());
        for (int j = l; j >= 0; j--){
            if (ans.substr(ans.size() - j, j) == s[i].substr(0, j)){
                ans += s[i].substr(j, s[i].size() - j);
                break;
            }
        }
    }
    return ans.size();
}

int main(){
    int t;
    cin >> t;
    int cnt = 1;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        int ans = INF;
        sort(s, s + n);
        do {
            ans = min (ans, solve());
        }while (next_permutation(s, s + n));
        printf("Case %d: %d\n", cnt++, ans);
    }
    return 0;
}