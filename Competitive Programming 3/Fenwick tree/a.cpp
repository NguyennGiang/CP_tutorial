#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long a[N], f[N];
int n, q;

void update(int id, int val){
    while (id <= n){
        f[id] += val;
        id += id & -id;
    }
}

long long getSum(int id){
    long long sum = 0;
    while (id > 0){
        sum += f[id];
        id -= id & -id;
    }
    return sum;
}

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        update(i, a[i] - a[i-1]);
    }
    
    // for (int i = 1; i <= n; i++){
    //     cout << f[i] << " ";
    // }
    while (q--){
        int op, l, r, k; 
        scanf("%d", &op);
        if (op == 1){
            scanf("%d%d%d", &l, &r, &k);
            update(l, k);
            update(r + 1, -k);
        }
        else {
            scanf("%d", &k);
            printf("%lld\n", getSum(k));
        }
    }
    return 0;
}
