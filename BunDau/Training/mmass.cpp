/*
    problem description: https://oj.vnoi.info/problem/mmass
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

string s;
map<char, int> m;

void init(){
    m['2'] = m['3'] = m['4'] = m['5'] = m['6'] = m['7'] = m['8'] = m['9'] = 2;
    m['O'] = 16;
    m['H'] = 1;
    m['C'] = 12;
    m['('] = 0;
    m[')'] = -1;
}

void solve(){
    init();
    cin >> s;
    // cout << s << endl;
    stack<int> st;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == 'C' || s[i] == 'H' || s[i] == 'O'){
            st.push(m[s[i]]);
        }
        else if (m[s[i]] == 2){
            int a = s[i] - 48;
            int b = st.top();
            st.pop();
            st.push(a * b);
        }
        else  if (m[s[i]] == - 1){
            int res = 0;
            while(st.top() != 0){
                res += st.top();
                st.pop();
            }
            st.pop();
            st.push(res);
        }
    }

    int res = 0;
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout << res;
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