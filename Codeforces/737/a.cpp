#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ld long double
int main() {
    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while (t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int &ai : a) cin >> ai;

        sort(a.begin(), a.end());
        long long sum = 0;
        for (int i = 0; i < n - 1; i++){
            sum += a[i];
        }
        cout << 1.0 * (sum)/ (n - 1) + (a[n-1]);
        cout << endl;
    }
    return 0;
}