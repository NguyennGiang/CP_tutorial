/* UVA11952 Arithmetic */

#include <iostream>
#include <string>
using namespace std;
#define ll long long 
ll getNum(string &s, int base){

    ll res = 0;

    for (auto c : s){
        if (base == 1 && c != '1') return -1;
        if (base > 1 && base <= c - '0') return -1;

        res *= base;
        res += c - '0';
    }
    return res;

}

void solve(){
    string a, op, b, eq, c;
    cin >> a >> op >> b >> eq >> c;
    int ans = 0;
    for (int i = 1; i < 100; i++){
        ll as = getNum(a, i);
        ll bs = getNum(b, i);
        ll cs = getNum(c, i);
        
        if (as < 0 || bs < 0 || cs < 0) {
            continue;
        }
      //  cout << as << " " << bs << " " << cs << endl;
        if (as + bs == cs){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}