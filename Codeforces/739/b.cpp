#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int dist = 2 * (b - a);
        int ans;
        if (b > dist || c > dist){
            ans = -1;
        }
        else {
            ans = c + dist / 2;
            if (ans > dist){
                ans = c - dist / 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}