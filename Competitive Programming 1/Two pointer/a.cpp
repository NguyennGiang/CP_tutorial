#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    sort(a, a+n);
    int j = 0;
    for (int i = 0; i < n; i++){

        while (j < n && a[j] - a[i] <= 5)
        {
            j++;
            
        }
        ans = max(ans, j - i);
    }
    cout << ans << '\n';
    return 0;
}