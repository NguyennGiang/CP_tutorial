#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int N = 100000 + 5;
int n;
int a[N];
int l[N], r[N];
stack<int> st;
int ans;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    st = stack<int> {};
        for (int j = 1; j <= n; j++){
            while (!st.empty() && a[j] <= a[st.top()]){
                st.pop();
            }
            l[j] = st.empty() ? 1 : st.top() + 1;
            st.push(j);
        }

        st = stack<int> {};

        for (int j = n; j >= 1; j--){
            while(!st.empty() && a[j] <= a[st.top()]) st.pop();
            r[j] = st.empty() ? n : st.top() - 1;
            st.push(j);
        }

        for (int j = 1; j <= n; j++){
            ans = max(ans, (r[j] - l[j] + 1) * a[j]);
        }
        cout << ans << endl;
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
    cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}