#include <bits/stdc++.h>
using namespace std;

int getlen(int x){
    int cnt = 0;
    while(x != 0){
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();
    s = '#' + s;

    vector <int> ans(n + 1, 1e6);
    ans[0] = 0, ans[1] = 2;

    for (int i = 1; i <= n; i++){
        string s1 = s.substr(1, i);
        reverse(s1.begin(), s1.end());

        ans[i] = min(ans[i], ans[i-1] + 2);

        vector <int> p(i, 0);
        for (int j = 1; j < i; j++){
            int k = p[j-1];
            while(k > 0 && s1[j] != s1[k]){
                k = p[k-1];
            }
            if (s1[j] == s1[k]) k++;
            p[j] = k;
            int len = j + 1;

            if ((j + 1) % (j + 1 - p[j]) == 0) len = j + 1 - p[j];
            int cnt = (j + 1) / len;

            ans[i] = min(ans[i], ans[i-j-1] + getlen(cnt) + len);
        }
    }
    cout << ans[n] << endl;
    return 0;
}