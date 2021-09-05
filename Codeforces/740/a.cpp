#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    scanf("%d", &tt);
    while (tt--){
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        for (int &ai : a) scanf("%d", &ai);

        int ans = 0;
        while(!is_sorted(a.begin(), a.end())){
            for (int i = ans % 2; i + 1 < n; i+=2){
                if (a[i] > a[i+1]){
                    swap(a[i], a[i+1]);
                }
            }
            ans++;

        }
        printf("%d\n", ans);
    }
    return 0;
}