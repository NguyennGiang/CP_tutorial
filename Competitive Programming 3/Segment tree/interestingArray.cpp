#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct node 
{
    int l, r;
    int v;
    int lazy;
}p[N << 2];

int lr[N], rr[N], vr[N];
int n, m;

void pushup(int cur){
    p[cur].v = p[cur << 1].v & p[cur << 1|1].v;
}

void pushdown(int cur){
    if (p[cur].lazy){
        p[cur << 1].lazy |= p[cur].lazy;
        p[cur << 1 | 1].lazy |= p[cur].lazy;
        p[cur << 1].v |= p[cur].lazy;
        p[cur << 1 | 1].v |= p[cur].lazy;
        p[cur].lazy = 0;
    }
}

void build(int l, int r, int cur){
    p[cur].l = l;
    p[cur].r = r;
    p[cur].lazy = p[cur].v = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    build(l, mid, cur << 1);
    build(mid + 1, r, cur << 1 | 1);
    pushup(cur);
} 

void update(int l, int r, int x, int cur){
    int L = p[cur].l;
    int R = p[cur].r;
    if (l <= L && R <= r){
        p[cur].lazy |= x;
        p[cur].v |= x;
        return;
    }
    pushdown(cur);
    int mid = L + R >> 1;
    if (r <= mid) update(l, r, x, cur << 1);
    else if (l > mid) update(l, r, x, cur << 1 | 1);
    else {
        update(l, mid, x, cur << 1);
        update(mid + 1, r, x, cur << 1 | 1);
    }
    pushup(cur);
}

int query(int l, int r, int cur){
    int L = p[cur].l;
    int R = p[cur].r;
    if (l <= L && R <= r){
        return p[cur].v;
    }
    pushdown(cur);
    int mid = L + R >> 1;
    if (r <= mid) return query(l, r, cur << 1);
    else if (l > mid) return query(l, r, cur << 1 | 1);
    else return query(l, mid, cur << 1) & query(mid + 1, r, cur << 1 | 1);
}

int main(){
    cin >> n >> m;
    build(1, n, 1);
    for (int i = 1; i <= m; i++){
        cin >> lr[i] >> rr[i] >> vr[i];
        update(lr[i], rr[i], vr[i], 1);
    }
    bool done = 1;
    for (int i = 1; i <= m; i++){
        if(query(lr[i], rr[i], 1) != vr[i]){
            done = 0;
            break;
        }
    }
    if (done){
        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            cout << query(i, i, 1) << " ";
        }
    }
    else cout << "NO";
    return 0;
}