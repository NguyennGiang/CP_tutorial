#include <bits/stdc++.h>
using namespace std;

const int N = 20;
bool legal[1 << N];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++){
        legal[i] = true;
    }
    while(m--){
        int a, b, x;
        cin >> a >> b;
        a--, b--;
        x = (1 << a) + (1 << b);
        for (int i = 0; i < (1 << n); i++){
            if ((x & i) == x){
                legal[i] = false; 
            }
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++){
        if (legal[i]){
            res ++;
        }
    }    
    cout << res << '\n';
    return 0;
}