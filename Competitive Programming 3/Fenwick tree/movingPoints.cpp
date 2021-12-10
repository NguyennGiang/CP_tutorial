/*
    x1 < x2 < x3 ... < xn;

    -j < i --> xi > xj
        +vj <= vi --> d = 0;
        + vj > vi --> d = xi - xj
            + y1, y2, ..., yk. --> d = (xi - y1) + (xi - y2) + ... = k * xi - (y1 + y2 + ....)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;

struct node{
    int x, v;
    bool operator<(const node &a) const{
        return x < a.x;
    }
}p[N];

ll num[N], sum[N];
int b[N];
int n;

ll get(ll c[], int x){
    ll ans = 0;
    while(x){
        ans += c[x];
        x -= x & -x;
    }
    return ans;
}

void add(ll c[], int x, ll v){
    while (x < N){
        c[x] += v;
        x += x & -x;
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].v;
        b[i] = p[i].v;
    }
    sort (p + 1, p + 1 + n);
    sort (b + 1, b + 1 + n);

    int len = unique(b + 1, b + 1 + n) - b - 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int pos = lower_bound(b + 1, b + 1 + len, p[i].v) - b;
        ans += get(num, pos) * (ll)p[i].x - get(sum, pos);
        add(num, pos, 1);
        add(sum, pos, p[i].x);
    }
    cout << ans;
    return 0;
}   