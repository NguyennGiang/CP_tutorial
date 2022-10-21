#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        long long res = 1LL * n * (n - 1) - 1LL * k * (a[n] | a[n-1]);
        for (int i = n; i >= 1; i--){
            if (1LL * i * i <= res) break;
            for (int j = n; j >= 1; j--){
                if (i == j) continue;
                if (1LL * i * j <= res) break;
                long long tmp = 1ll * i * j - 1LL * k * (a[i] | a[j]);
                res = max (res, tmp);
            }
        }
        cout << res << endl;
    }
    return 0;
}