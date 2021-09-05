#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
string a, b;

void solve(int t) {
    cin >> n; 
    cin >> a >> b;
    a = "X" + a + "X";
    b = "X" + b + "X";
    int cnt = 0; 
    for (int i = 1; i <= n; i++){
        if (a[i] == '.' && a[i-1] == 'X' && a[i+1] == 'X' && b[i] == '.') {
            cnt++;
            a[i] = 'G';
            b[i] = 'G';
            for (int j = i + 1; j <= n && b[j] == '.'; j++) b[j] = 'G';
            for (int j = i - 1; j >= 0 && b[j] == '.'; j--) b[j] = 'G';
        }
        if (b[i] == '.' && b[i-1] == 'X' && b[i+1] == 'X' && a[i] == '.') {
            cnt++;
            a[i] = 'G';
            b[i] = 'G';
            for (int j = i + 1; j <= n && a[j] == '.'; j++) a[j] = 'G';
            for (int j = i - 1; j >= 0 && a[j] == '.'; j--) a[j] = 'G';
        }
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == '.') {
            cnt++; 
            a[i] = 'G';
            for (int j = i + 1; j <= n && a[j] == '.'; j++) a[j] = 'G';
        }
        if (b[i] == '.') {
            cnt++;
            b[i] = 'G';
            for (int j = i +1; j <= n && b[j] == '.'; j++) b[j] = 'G';
        }
    }
    cout << "Case #" << t << ": " << cnt << "\n";
    
}

int main(){
    int t; 
    cin >> t; 
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}
