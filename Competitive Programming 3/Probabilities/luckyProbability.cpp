#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pl, pr;
ll vl, vr;
int k;
vector<ll> a;

void gen(ll v){
    if (v > 1e9) return;
    a.push_back(v);
    gen(v * 10 + 4);
    gen(v * 10 + 7);
}

ll calc(ll l1, ll r1, ll vl, ll vr){
    ll l = max(l1, vl);
    ll r = min(r1, vr);
    if (l <= r) return r - l + 1;
    return 0;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> pl >> pr >> vl >> vr >> k;
    
    gen(4); gen(7);
    a.push_back(0);
    a.push_back(1000000001);
    sort(a.begin(), a.end());
    ll res = 0;
    ll sum = (pr - pl + 1) * (vr - vl + 1);
    int l = 1, r = l + k;
    while(r < a.size()){
        int l1 = a[l-1] + 1;
        int r1 = a[l];
        int l2 = a[r-1];
        int r2 = a[r] - 1;
        res += calc(l1, r1, pl, pr) * calc(l2, r2, vl, vr);
        res += calc(l2, r2, pl, pr) * calc(l1, r1, vl, vr);
        if (r1 == l2 && (pl <= r1 && r1 <= pr && vl <= r1 && r1 <= vr)) res--;
        l++;
        r++;
    }
    cout << fixed << setprecision(10) << (double)res / (double)sum;
    return 0;
}