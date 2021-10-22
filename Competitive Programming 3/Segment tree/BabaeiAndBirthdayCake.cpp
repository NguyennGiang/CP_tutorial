#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
const float pi = 3.141592654;
int r[N], h[N];
ll tree[4 * N];

ll update(int node, int l, int r, int pos, ll val){
    if (l > pos || r < pos) return tree[node];
    if (l == r) return tree[node] = max(tree[node], val);
    int mid = (l + r) >> 1;
    return tree[node] = max(update(node << 1, l, mid, pos, val), update(node << 1 | 1, mid + 1, r, pos, val));
}

ll query(int node, int l, int r, int i, int j){
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return tree[node];
    int mid = l + r >> 1;
    return max(query(node << 1, l, mid, i, j), query(node<<1|1, mid + 1, r, i, j));
}

int main(){
    int n; cin >> n;
    vector <ll> v;
    cout << setprecision(12) << fixed;
    for  (int i = 0; i < n; i++){
        cin >> r[i] >> h[i];
        v.push_back(1LL * r[i] * r[i] * h[i]);
    }
    sort(v.begin(), v.end());
    map <ll, ll> mp;

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (i == 0 || v[i] != v[i-1]){
            mp[v[i]] = ++cnt;
        }
    }

    for (int i = 0; i < n; i ++){
        ll val = 1LL * r[i] * r[i] * h[i];
        int id = mp[val];
        ll mx = val + query(1, 0, cnt, 0, id - 1);
        update(1, 0, cnt, id, mx);
    }
    cout << acos(-1) * tree[1];
    return 0;
}