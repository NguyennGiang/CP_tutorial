#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;

int z_function(){
    vector<int> z(int(s.length()), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++){
        if (i <= r){
            z[i] = min(r - i + 1, z[i-l]);
        }
        while(i + z[i] < s.length() && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = n + 1; i < s.length(); i++){
        if (z[i] == n){
            return n - (i - n - 1);
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> t;
    s = s + s;
    s = t + char(0) + s;
    int res = z_function();
    cout << res << endl;
    return 0;
}

