/*
    @Description
        - Vasya has two arrays A and B of lengths nn and mm, respectively.
        - he takes some consecutive subsegment of the array and replaces it with a single element, equal to the sum of all elements on this subsegment.
        - Two arrays A and B are considered equal
        - Help Vasya to determine the maximum length of the arrays that he can achieve or output that it is impossible to make arrays A and B equal.        
    @Algorithms
        - two pointer:
            + A_sum < B_sum --> id_A ++;
            + A_sum > B_sum -> id_B++;
*/



#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6; 

int m, n, a[maxn], b[maxn];
void solve(){
    cin >> n; 
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0;
    ll asum = a[0], bsum = b[0];
    int cnt = 0;
    while (i < n && j < m)
    {
        
        if (asum == bsum) { 
            i++; 
            j++;
            asum += a[i];
            bsum += b[j];
            cnt++;
        }
        else if (asum < bsum) {
            i++;
            asum += a[i];

        }
        else {
            j++;
            bsum += b[j];
        }
    }
    if (asum == bsum){
        cout << cnt << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main(){
    solve();
    return 0;
}