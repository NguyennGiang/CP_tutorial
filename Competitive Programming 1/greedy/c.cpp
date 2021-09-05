#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    string s; 
    cin >> s;
    int cnt[256];
    int res[10];
    memset(cnt, 0, sizeof(cnt));
    memset(res, 0, sizeof(res));
    for (char i : s) cnt[i]++;
    cout << "Case #" << t << ": ";
    while(cnt['Z']){
        res[0]++;
        cnt['Z']--; 
        cnt['E']--;
        cnt['R']--;
        cnt['O']--;
    }
    while(cnt['G']){
        res[8]++;
        cnt['E']--;
        cnt['I']--;
        cnt['G']--;
        cnt['H']--;
        cnt['T']--;
    }
    while(cnt['H']){
        res[3]++;
        cnt['T']--;
        cnt['H']--;
        cnt['R']--;
        cnt['E']--;
        cnt['E']--;
    }
    while(cnt['W']){
        res[2]++;
        cnt['T']--;
        cnt['W']--;
        cnt['O']--;
    }
    while(cnt['R']){
        res[4]++;
        cnt['F']--;
        cnt['O']--;
        cnt['U']--;
        cnt['R']--;
    }
    while(cnt['X']){
        res[6]++;
        cnt['S']--;
        cnt['I']--;
        cnt['X']--;
    }
    while(cnt['F']){
        res[5]++;
        cnt['F']--;
        cnt['I']--;
        cnt['V']--;
        cnt['E']--;
    }
    while(cnt['S']){
        res[7]++;
        cnt['S']--;
        cnt['E']--;
        cnt['V']--;
        cnt['E']--;
        cnt['N']--;
    }
    while(cnt['I']){
        res[9]++;
        cnt['N']--;
        cnt['I']--;
        cnt['N']--;
        cnt['E']--;
    }
    while(cnt['O']){
        res[1]++;
        cnt['O']--;
        cnt['N']--;
        cnt['E']--;
    }
    for (int i = 0; i < 10; i++){
        while(res[i]--){
            cout << i;
        }
    }
    cout << endl;
}

int main() {
    int t; 
    cin >> t; 
    for (int tc = 1; tc <= t; tc++){
        solve(tc);

    }

    return 0;
}
 