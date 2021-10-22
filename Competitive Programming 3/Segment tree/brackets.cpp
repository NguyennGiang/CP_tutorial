#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct node {
    int cs, o, c;
}tree[4 * N];

char str[N];

node combine(node a, node b){
    node res;
    int tmp = min(a.o, b.c);
    res.cs = a.cs + b.cs + tmp;
    res.o = a.o + b.o - tmp;
    res.c = a.c + b.c - tmp;
    return res;
}

void build(int cur, int l, int r){
    if (l == r){
        if (str[l] == '('){
            tree[cur].cs = tree[cur].c = 0;
            tree[cur].o = 1;
        }
        else {
            tree[cur].cs = tree[cur].o = 0;
            tree[cur].c = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(cur << 1, l, mid);
    build(cur << 1 | 1, mid + 1, r);
    tree[cur] = combine(tree[cur<<1], tree[cur << 1 | 1]);
}

node query(int cur, int lo, int hi, int l, int r){
    if (l == lo && r == hi){
        return tree[cur];
    }
    int mid = (lo + hi) / 2;
    if (r <= mid){
        return query(cur << 1, lo, mid, l, r);
    }
    else if (l > mid) return query(cur << 1 | 1, mid + 1, hi, l , r);
    else return combine(query(cur << 1, lo, mid, l, mid), query(cur << 1 | 1, mid + 1, hi, mid + 1, r));
}

int main(){
    cin >> str;
    int n = strlen(str);
    int q; cin >> q;

    build(1, 0, n - 1);

    int x, y;
    while (q--){
        cin >> x >> y;
        x--; y--;
        node ans = query(1, 0, n - 1, x, y);
        cout << 2 * ans.cs << endl;
    }
}