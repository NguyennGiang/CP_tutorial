#include <bits/stdc++.h>
using namespace std;

const int weight[6] = {1, 2, 5, 10, 15, 20};
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector <int> p(n);
    for (int &pi : p) cin >> pi;
    int sum = 0;
    for (int pi : p) sum += pi;
    reverse(p.begin(), p.end());
    int w; cin >> w;
    int dp[w + 1];
    for (int i = 0; i <= w; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int we : weight){
        for (int j = we; j <= w; j++){
            dp[j] = min(dp[j], dp[j - we] + 1);
        }
    }
    int steps = INF;
    if (sum <= w){
        steps = min(steps, dp[w - sum]);
    }
    int cur = 0;
    for (int pi : p){
        sum -= pi;
        cur++;
        if (sum <= w){
            int tmp = cur + dp[w - sum];
            steps = min(steps, tmp);
        }
    }
    cout << steps;
    return 0;
}