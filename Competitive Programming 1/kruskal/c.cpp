#include <iostream>
#include <vector>
#define ll long long
#define RASENGAN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main(){

    RASENGAN
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
    }
    cin >> m;
    int cost[n + 1] = {0};
    bool check[n + 1] = {};

    ll total = 0, childs = 0;

    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (check[b] == 0){
            childs++;
            total += c;
            cost[b] = c;
            check[b] = true;
        }
        else {
            if (cost[b] > c){
                total = total - cost[b] + c;
                cost[b] = c;
            }
        }
    }

    if (childs == n - 1){
        cout << total << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}