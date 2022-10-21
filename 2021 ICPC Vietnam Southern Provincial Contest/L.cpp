#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    multiset<int>even, odd;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        if (x % 2 == 0) even.insert(x);
        else odd.insert(x);
    }
    string s; cin >> s;
    int res = 0;
    for (char c : s){
        if (c  == '0'){
            multiset<int> tmp;
            for (int x : even){
                sum -= x / 2;
                if(x % 4 == 0) tmp.insert(x/2);
                else odd.insert(x / 2);
            }
            swap(tmp, even);
        }
        else {
            for (int x : odd){
                sum--;
                if(x - 1 > 0){
                    even.insert(x - 1);
                }
            }
            odd.clear();
        }
        cout << sum << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
