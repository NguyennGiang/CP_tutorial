#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;
vector <pii> v;
int knapSack(int W, int n){
    if (n == 0 || W == 0){
        return 0;
    }

    else if (v[n - 1].first > W){
        return knapSack(W, n - 1);
    }
    else {
        return max(
            v[n-1].second + knapSack(W - v[n-1].first, n - 1),
            knapSack(W, n - 1)
        );
    }

}

int main(){
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    cout << knapSack(W, n);
    return 0;
}