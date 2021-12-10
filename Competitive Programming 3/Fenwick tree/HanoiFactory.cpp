#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int n;
ll f[N];

struct node {
    long long a, b, h;
}itm[N];

bool cmp(node x, node y){
    if (x.b != y.b){
        return x.b < y.b;
    }
    return x.a < y.a;
}

void add(int id, ll val){
    while (id <= n){
        f[id] = max(f[id], val);
        id += id & -id;
    }
}

long long get(int id){
    long long ans = 0;
    while (id > 0){
        ans = max(ans, f[id]);
        id -= id & -id;
    }
    return ans;
}

ll b[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> itm[i].a >> itm[i].b >> itm[i].h;
    }
    sort(itm + 1, itm + 1 + n, cmp);
    for (int i = 1; i <= n; i++){
        b[i] = itm[i].b;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int a = itm[i].a;
        int id = upper_bound(b + 1, b + 1 + n, a) - b;
        ll pmax = get(n + 1 - id);
        // cout << id <<  " " << pmax << " " << itm[i].h << endl;
        ans = max(ans, pmax + itm[i].h);
        add(n+1-i, pmax + itm[i].h);
        // for (int i = 1; i <= n; i++) cout << f[i] << " ";
        // cout << endl;
    }
    cout << ans;
    return 0;
}