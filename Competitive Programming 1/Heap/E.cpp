#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int t){
    int n, m; 
    cin >> n >> m;
    ll ans = 0;  
    priority_queue <ll, vector<ll>, greater<> > sum; 
    for (int i = 0; i < n; i++){
        vector <ll> price;
        for(int j = 0; j < m; j++){
            int num; 
            cin >> num;
            price.push_back(num);
        }
        sort(price.begin(), price.end());
        for (int j = 0; j < m; j++){
            ll val = price[j] + (j * 2 + 1);
            sum.push(val);
        }
        cout << sum.top() << endl;
        ans += sum.top();
        sum.pop();
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main(){
    int t; 
    cin >> t; 
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}