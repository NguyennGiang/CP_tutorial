#include <bits/stdc++.h>
using namespace std;
#define N 100005

struct tree {
    int l, r;
    int x, y;
}t[N << 2];

int a[N], b[N];

void pushdown(int p){
    if (t[p].x){
        t[p << 1].x = t[p].x;
        t[p << 1].y = t[p].y;
        t[p << 1 | 1].x = t[p].x;
        t[p << 1 |1].y = t[p].y;
        t[p].x = 0;
    }
}

void build(int p, int l, int r){
    t[p].l = l, t[p].r = r;
    t[p].x = t[p].y = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void update(int p, int l, int r, int x, int y){
    if (t[p].l == l && t[p].r == r){
        t[p].x = x;
        t[p].y = y;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid){
        update(p << 1, l, r, x, y);
    }
    else if (l > mid){
        update(p << 1 | 1, l, r, x, y);
    }
    else {
        update(p << 1, l, mid, x, y);
        update(p << 1 | 1, mid + 1, r, x, y);
    }
}

struct node {
    int x, y;
};

node query(int p, int x){
    node tmp;
    if (t[p].l == t[p].r){
        tmp.x = t[p].x;
        tmp.y = t[p].y;
        return tmp;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (x > mid)
        return query(p << 1 | 1, x);
    return query(p << 1, x);
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);

    build(1, 1, n);

    while (q--){
        int t, x, y, z;
        scanf("%d", &t);
        if (t == 1){
            scanf("%d%d%d", &x, &y, &z);
            update(1, y, y + z - 1, x, y);
        }
        else {
            scanf("%d", &x);
            node tmp = query(1, x);
            if (tmp.y == 0){
                printf("%d\n", b[x]);
            }
            else {
                printf("%d\n", a[x - tmp.y + tmp.x]);
            }
        }
    }
    return 0;
}