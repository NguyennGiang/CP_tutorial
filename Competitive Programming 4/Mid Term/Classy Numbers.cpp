#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;
using ll = long long;

void gen(ll pos, ll cnt, ll num){
    if (pos > 18){
        v.push_back(num);
        return;
    }
    gen(pos + 1, cnt, num * 10);
    if (cnt < 3){
        for (int i = 1; i <= 9; i++){
            gen(pos + 1, cnt + 1, num * 10 + i);
        }
    }
}

int main(){
    gen(1, 0, 0);
    v.push_back(1000000000000000000);

    ll n, l, u;
    cin >> n;
    while(n--){
        cin >> l >> u;
        cout << upper_bound(v.begin(), v.end(), u) - lower_bound(v.begin(), v.end(), l) << endl;
    }
    return 0;
}