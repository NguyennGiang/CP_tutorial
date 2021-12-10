#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long Mod = 1e9 + 7;
int n, a[N];
long long s[4 * N];
long long l_value[4 * N], r_value[4 * N];
long long L[4 * N], R[4 * N];
long long len[4 * N];

void pushup(int i){
    len[i] = len[2 * i] + len[2 * i + 1];
    s[i] = s[2 * i] + s[2 * i + 1];
    L[i] = L[2 * i];
    R[i] = R[2 * i + 1];
    l_value[i] = l_value[2 * i];
    r_value[i] = r_value[2 * i + 1];
    if (l_value[2 * i + 1] == r_value[2 * i] + 1){
        s[i] += R[2 * i] * L[2 * i + 1];
        s[i] %= Mod;
    }
    if (l_value[2 * i + 1] == r_value[2 * i] + 1 && L[2 * i] == len[2 * i]){
        L[i] = L[2 * i] + L[2 * i + 1];
    }
    if (l_value[2 * i + 1] == r_value[2 * i] + 1 && R[2 * i + 1] == len[2 * i + 1]){
        R[i] = R[2 * i + 1] + R[2 * i];
    }
}

void build(int i, int l, int r){
    if (l == r){
        s[i] = 1;
        l_value[i] = a[l];
        r_value[i] = a[r];
        L[i] = 1;
        R[i] = 1;
        len[i] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    pushup(i);
}

void update(int i, int l, int r, int k, int value){
    if (l == r){
        s[i] = 1;
        l_value[i] = value;
        r_value[i] = value;

        L[i] = 1;
        R[i] = 1;
        len[i] = 1;
        return;
    }
    int mid = (l + r) / 2;
    if (k > mid){
        update(2 * i + 1, mid + 1, r, k, value);
    }
    else {
        update(2 * i, l, mid, k, value);
    }

    pushup(i);
}

long long get(int i, int l, int r, int cl, int cr){
    if (l == cl && r == cr){
        return s[i];
    }

    int mid = (l + r) / 2;
    if (cl > mid){
        return get(2 * i + 1, mid + 1, r, cl, cr);
    }
    else if (cr <= mid) return get(2 * i, l, mid, cl, cr);

    long long A = get(2 * i, l, mid, cl, mid);
    long long B = get(2 * i + 1, mid + 1, r, mid + 1, cr);

    long long len_right = min(R[2 * i], (long long)(mid - cl + 1));
    long long len_left = min(L[2 * i + 1], (long long) (cr - (mid + 1) + 1));
    long long res = A + B;
    if (r_value[2 * i] + 1 == l_value[2 * i + 1]){
        res += len_left * len_right;
    }
    return res % Mod;
}

void solve(int test){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    build(1, 0, n - 1);
    int m;
    scanf("%d", &m);
    long long res = 0;
    for (int i = 1; i <= m; i++){
        int mode;
        scanf("%d", &mode);
        if (mode == 0){
            int p, k;
            scanf("%d%d" ,&p, &k);
            update(1, 0, n - 1, p, k);
        }
        else {
            int l, r;
            scanf("%d%d", &l, &r);
            res += get(1, 0, n - 1, l, r);
            res %= Mod;
        }
    }
    printf("Case #%d: %d\n", test, (int)(res));
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}