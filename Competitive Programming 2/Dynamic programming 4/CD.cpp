#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int track[N];
int n, t;
vector <int> container;
vector <int> ans;
int maxSum;

void solve(int pos, int sum){
    if (sum > maxSum){
        ans = container;
        maxSum = sum;
    }

    for (int i = pos; i < t; i++){
        if (track[i] + sum <= n){
            sum += track[i];
            container.push_back(track[i]);

            solve(i + 1, sum);

            sum -= track[i];
            container.pop_back();
        }
    }
}

int main(){
    while (cin >> n >> t){
        for (int i = 0; i < t; i++){
            cin >> track[i];
        }
        container.clear();
        maxSum = 0;
        solve(0, 0);

        int sum = 0;
        for (int x : ans){
            cout << x << " ";
            sum += x;
        }
        cout << "sum:" << sum << endl;
    }   
    return 0;
}