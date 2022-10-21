#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

int a[1005], h[1005];
int l[1005], r[1005];
int n, m;
stack<int> st;
int ans ;

void solve(){
    cin >> n >> m;
    cout << "result: ";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) cin >> a[j];
        for (int j = 1; j <= m; j++){
            if (a[j] == 1) h[j]++;
            else h[j] = 0;
        }
        st = stack<int> {};
        for (int j = 1; j <= m; j++){
            while (!st.empty() && h[j] <= h[st.top()]){
                st.pop();
            }
            l[j] = st.empty() ? 1 : st.top() + 1;
            st.push(j);
        }

        st = stack<int> {};

        for (int j = m; j >= 1; j--){
            while(!st.empty() && h[j] <= h[st.top()]) st.pop();
            r[j] = st.empty() ? m : st.top() - 1;
            st.push(j);
        }

        for (int j = 1; j <= m; j++){
            ans = max(ans, (r[j] - l[j] + 1) * h[j]);
        }
    }
    cout << ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}