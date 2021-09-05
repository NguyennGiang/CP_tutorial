#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int power = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for (int j = 0; j < x; j++){
            int armor;
            cin >> armor;
            power = max(power, armor - j + 1);
        }
    }
    cout << power << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;

}