#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int tree[N << 2][21], lazy[N << 2][21];
int a[N];

void pushup(int root, int pos){
    tree[root][pos] = tree[root<<1][pos] + tree[root<<1|1][pos];
}

void change(int l, int r, int root, int pos){
    tree[root][pos] = r - l + 1 - tree[root][pos];
    lazy[root][pos] ^= 1;
}

void pushdown(int l, int r, int root, int pos){
    if (lazy[root][pos]){
        int mid = (l + r) >> 1;
        change(l, mid, root << 1, pos);
        change(mid + 1, r, root << 1|1, pos);
        lazy[root][pos] = 0;
    }
}

void build(int l, int r, int root, int pos){
    if (l == r){
        int tmp = (a[l] >> pos) & 1;
        tree[root][pos] = tmp;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1, pos);
    build(mid + 1, r, root << 1|1, pos);
    pushup(root, pos);
}

int query(int l, int r, int L, int R, int root, int pos){
    if (L <= l && R >= r){
        return tree[root][pos];
    }
    pushdown(l, r, root, pos);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid) ans += query(l, mid, L, R, root << 1, pos);
    if (R > mid) ans += query(mid + 1, r, L, R, root << 1 | 1, pos);
    return ans;
}

void update(int l, int r, int L, int R, int root, int pos){
    if (L <= l && R >= r){
        change(l, r, root, pos);
        return;
    }
    pushdown(l, r, root, pos);
    int mid = (l + r) >> 1;
    if (L <= mid) update(l, mid, L, R, root << 1, pos);
    if (R > mid) update(mid + 1, r, L, R, root << 1 | 1, pos);
    pushup(root, pos);
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 0; i <= 20; i++) build(1, n, 1, i);

    int m; scanf("%d", &m);
    while (m--){
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1){
            ll ans = 0;
            for (int i = 0; i <= 20; i ++){
                ans += 1ll * (1 << i) * (query(1, n, l, r, 1, i));
            }
            printf("%lld\n", ans);
        }
        else {
            int x; scanf("%d", &x);
            for (int i = 0; i <= 20; i++){
                if ((x >> i) & 1) update(1, n, l, r, 1, i);
            }
        }
    }
    return 0;
}