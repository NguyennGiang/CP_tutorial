#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector<int> p[N];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();
    string t = s + s;
 
    for (int i = 0; i < n; ++i) {
        p[s[i] - 'a'].push_back(i);
    }
 
    int ans = 0;
 
    for (int i = 0; i < 26; ++i) {
        int mx = 0;
 
        for (int j = 0; j < n; ++j) {
            vector<int> cnt(26, 0);
            for (int x : p[i]) {
                ++cnt[t[x + j] - 'a'];
            }
 
            int cur = 0;
            for (int y : cnt) {
                cur += (y == 1);
            }
 
            mx = max(mx, cur);
        }
 
        ans += mx;
    }
    cout << fixed << setprecision(20);
    cout << 1.0 * ans / n << "\n";
    return 0;
}