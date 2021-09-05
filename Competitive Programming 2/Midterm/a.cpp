#include <bits/stdc++.h>
using namespace std;
#define S(x, y) x * y

int area(int x, int y){
    return x * y;
}

int main(){
    int a = 4;
    int b = 5;
    cout << S(a + 1, b) << "  " << area(a + 1, b);
    return 0;
}