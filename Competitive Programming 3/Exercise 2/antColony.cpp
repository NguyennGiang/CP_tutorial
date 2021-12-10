#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

struct node {
    int minv;
    int num;
    int gc;
}tree[N << 2];

void build(int rt, int l, int r){
    if (l == r){
        cin >> tree[rt].minv;
        tree[rt].num = 1;
        tree[rt].gc = tree[rt].minv;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l , mid);
    build(rt << 1 | 1, mid + 1, r);
    if (tree[rt << 1].minv < tree[rt << 1 | 1].minv){
        tree[rt].minv = tree[rt << 1].minv;
        tree[rt].num = tree[rt << 1].num;
    }
    else if (tree[rt << 1].minv > tree[rt << 1 | 1].minv) {
        tree[rt].minv = tree[rt << 1 | 1].minv;
        tree[rt].num = tree[rt << 1 | 1].num;
    }
    else {
        tree[rt].minv = tree[rt << 1].minv;
        tree[rt].num = tree[rt << 1].num + tree[rt << 1 | 1].num;
    }
    tree[rt].gc = gcd(tree[rt << 1].gc, tree[rt << 1 | 1].gc);
}

int minv, min_num, mgcd;

void query(int L, int R, int rt, int l, int r){
    if (L <= l && R >= r){
        if (minv > tree[rt].minv){
            minv = tree[rt].minv;
            min_num = tree[rt].num;
        }
        else if (minv == tree[rt].minv){
            min_num += tree[rt].num;
        }

        mgcd = gcd(mgcd, tree[rt].gc);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid){
        query(L, R, rt << 1, l, mid);
    }
    if (R > mid){
        query(L, R, rt << 1 | 1, mid + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    build(1, 1, n);
    int m, l, r;
    cin >> m;
    while (m--){
        cin >> l >> r;
        minv = INT_MAX;
        min_num = 0;
        mgcd = 0;
        query(l, r, 1, 1, n);
        if (minv == mgcd){
            cout << r - l + 1 - min_num << endl;
        }
        else {
            cout << r - l + 1 << endl;
        }
    }
    return 0;
}