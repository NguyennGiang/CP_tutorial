/*
    problem description: https://oj.vnoi.info/problem/kplank
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 1e6 + 5;
int n;
int a[N], l[N], r[N];
stack<int> st;

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    st = stack<int> {};
    for (int i = 0; i < n; i++){
        while(st.size() && a[i] <= a[st.top()]) st.pop();
        l[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    st = stack<int> {};
    for (int i =  n - 1; i >= 0; i--){
        while(st.size() && a[i] <= a[st.top()]) st.pop();
        r[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    int len = 0;
    for (int i = 0; i < n; i++){
        int u = r[i] - l[i] + 1;
        if (u >= a[i]){
            len = max(len, a[i]);
        }
    }
    cout << len;
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