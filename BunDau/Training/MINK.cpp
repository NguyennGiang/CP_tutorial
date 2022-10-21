/*
    problem: https://oj.vnoi.info/problem/mink
    author: duckgiang  
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

int n, k;

void solve(){
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    deque<int> q;
    for(int i = 0; i < n; i++){
        // while(!q.empty() && q.fronf())
        while(!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        if (q.front() + k <= i){
            q.pop_front();
        }

        if (i + 1 >= k){
            cout << a[q.front()] << ' ';
        }
    }
    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

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