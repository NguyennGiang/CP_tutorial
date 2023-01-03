#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
map<int, int> cnt;
long long s;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 3; i <= n; i++){
        if (a[i] == a[i-1] && a[i] - a[i-2] == 1){
            cout << "cslnb";
            return;
        }
    }

    map<int, int>::iterator it;

    int pairs = 0;
    for (it = cnt.begin(); it != cnt.end(); it++){
        if (it -> second > 2){
            cout << "cslnb\n";
            return;
        }

        if (it -> second == 2){
            pairs ++;
        }
    }
    if (cnt[0] >= 2 || pairs >= 2){
        cout << "cslnb\n";
        return;
    }
    int move = s - n * (n-1) / 2;
    cout << (move % 2 == 0 ? "cslnb" : "sjfnb");
    cout << endl; 
}

int main(){
    solve();
    return 0;
}