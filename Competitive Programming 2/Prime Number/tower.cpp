#include <bits/stdc++.h>
using namespace std;

vector <int> prime_factor(int n){
    vector <int> res;
    int d = n;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (n !=  i * i){
                res.push_back(i);
                res.push_back(n / i);
            }
            else {
                res.push_back(i);
            }
           // n /= i;
        }
    }
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    if ((b % a) || (a <= 0) || (b <= 0)){
        cout << -1;
        return 0;
    }

    vector <int> p = prime_factor(b);
    // for (int pi : p) cout << pi << " ";
    // cout << endl;
    sort(p.begin(), p.end());
    int high = 0;
    int weight = 0;
    int pre = 1;
    for (int pi : p){
        if (pi >= a && pi % pre == 0){
            high++;
            weight += pi;
            pre = pi;
        }
    }
    cout << high << " " << weight;
    return 0;
}