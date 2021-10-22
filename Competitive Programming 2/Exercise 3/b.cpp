#include <bits/stdc++.h>
using namespace std;

const int c[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long d[30005]; 

int main(){
    d[0] = 1;
    for (int i = 0; i < 11; i++){
        for (int j = c[i]; j <= 30000; j++){
            d[j] += d[j - c[i]];
        }
    }

    double a;
    while (cin >> a && a){
        int n = int(a * 100 + 0.5);
        printf("%6.2lf%17lld\n", a, d[n]);
    }
    return 0;
}