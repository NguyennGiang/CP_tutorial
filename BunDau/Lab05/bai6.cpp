#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    if (a < 5.5) return 'D';
    if (a < 7) return 'C';
    if (a < 8.5) return 'B';
    return 'A';
}

int main(){
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        if (cal(a) == 'A') ++A;
        if (cal(a) == 'B') ++B;
        if (cal(a) == 'C') ++C;
        if (cal(a) == 'D') ++D;
        if (cal(a) == 'F') ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
