/*
    problem description: https://codeforces.com/contest/616/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

void solve(){
    string a, b;
    cin >> a >> b;
    string c = "";
    while(abs(int(a.size()) - int(b.size())) != int(c.size())) c += '0';
    if (a.size() < b.size()) a = c + a;
    else b = c + b;

    if (a < b){
        cout << "<";
    }
    else if (a > b) cout << ">";
    else cout << "=";
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