#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for (int &ai : a) cin >> ai;

        long long ans = 0;
        for (int i = 1; i < n; i++){
            ans = max(ans, 1LL * a[i] * a[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}