#include <bits/stdc++.h>
using namespace std;

int main(){
    int ways[7490];
    int coins[5] = {50, 25, 10, 5, 1};

    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for (int i = 1; i <= 5; i++){
        for (int j = coins[i -1]; j < 7490; j++){
            ways[j] += ways[j-coins[i-1]];
        }
    }
    int n;
    while(cin >> n){
        cout << ways[n] << endl;
    }
    return 0;
}