#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m, a[MAXN], dp_l[MAXN], dp_r[MAXN];

int main() {
    scanf("%d%d", &n, &m);    
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);

    dp_l[1] = 1;
    for(int i = 2; i <= n; ++i) 
        dp_l[i] = (a[i] <= a[i-1]) ? dp_l[i-1] : i;

    dp_r[n] = n;
    for(int i = n-1; i >= 1; --i)
        dp_r[i] = (a[i] <= a[i+1]) ? dp_r[i+1] : i;

    for(int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        
        bool ans = (dp_r[l] >= dp_l[r]);
        puts(ans ? "Yes" : "No"); 
    }

    return 0;
}