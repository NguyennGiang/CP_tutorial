#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);

const ll N = 1e5 + 5;

struct node {
    int ch[2];

    void init(){
        ch[0] = 0;
        ch[1] = 0;
    }
}tr[N * 50];

ll ans, pre[N], nex[N], a[N];
int tot, n;

void add(ll x){
    int now = 0, p = 0;
    for (int i = 50; i >= 0; i--){
        if ((1LL << i) & x) p = 1;
        else p = 0;
        if (!tr[now].ch[p]){
            tot++;
            tr[now].ch[p] = tot;
            tr[tot].init();
        }
        now = tr[now].ch[p];
    } 
}

ll solve(ll x){
    ll tmp = 0;
    int now = 0, p = 0;
    for (int i = 50; i >= 0; i--){
        if ((1LL << i) & x) p = 0;
        else p = 1;
        if(tr[now].ch[p]) tmp |= (1LL << i);
        else p ^= 1;
        now = tr[now].ch[p];
    }
    return tmp;
}

int main(){
    KAMEHAMEHA

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }

    for (int i = n; i >= 1; i--){
        nex[i] = nex[i + 1] ^ a[i]; 
    }

    //for (int i = 1; i <= n; i++) cout << a[i] << " " << pre[i] << " " << nex[i] << endl;

    for (int i = 1; i <= n + 1; i++){
        add(pre[i-1]);
        ans = max(ans, solve(nex[i]));
       //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}