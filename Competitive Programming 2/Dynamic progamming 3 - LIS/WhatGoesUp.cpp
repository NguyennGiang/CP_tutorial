#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 0;
    int x;
    vector <int> a;
    while (cin >> x) {
        a.push_back(x);
        n++;
    }

    vector <int> L(n);
    vector <int> dp(n, 1    );
    for (int i = 0; i < n; i++){
        int pos = lower_bound(L.begin(), L.end(), a[i]) - L.begin();
        dp[i] = pos + 1;
        if (pos == L.size()){
            L.push_back(a[i]);
        }
        else L[pos] = a[i];
    }

    int m = L.size();
    vector <int> ans;
    for (int i = n - 1; i >= 0; i--){
        if (dp[i] == m){
            ans.push_back(a[i]);
            m--;
        }   
    }
    cout << ans.size() << "\n-\n";
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << endl;
    }
    return 0;   
}