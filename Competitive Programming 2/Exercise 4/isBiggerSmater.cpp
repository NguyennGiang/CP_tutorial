#include <bits/stdc++.h>
using namespace std;

struct E
{
    int id, W, S;

    E() {} 

    E (int id, int W, int S) 
        :id(id), W(W), S(S) 
    {}

    bool operator < (E X){
        if (W != X.W) return W < X.W;
        return S > X.S;
    }  
};

int main(){
    int n, W, S;
    E a[10000];
    while (cin >> W >> S) a[n] = E(++n, W, S);

    sort(a, a + n);

    int dp[n], next[n];
    memset(dp, 0, sizeof(dp));
    memset(next, -1, sizeof(next));

    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--){
            if (a[i].W != a[j].W && a[i].S < a[j].S && dp[i] <= dp[j] + 1){
                dp[i] = dp[j] + 1;
                next[i] = j;
            }
        }
    }
    int ouput[1050];
    int st = 0, t = 0;
    for (int i = 0; i < n; i++){
        if (dp[st] < dp[i]){
            st = i;
        }
    }
    cout << dp[st] << endl;
    while (st != -1){
        ouput[t++] = st;
        st = next[st];
    }
    for (int i = t - 1; i >= 0; i--){
        cout << a[ouput[i]].id << endl;
    }
    return 0;
}