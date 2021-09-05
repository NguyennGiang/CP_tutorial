#include <bits/stdc++.h>
using namespace std;

bool isPrime[100005];

void init(){
    for (int i = 0; i <= 100000; i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= 100000; i++){
        if (isPrime[i]){
            for (int j = i * i; j <= 100000; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    init();
    string s;
    cin >> s;
    for (int i = 99999; i >= 2; i--){
        if (isPrime[i]){
            string x = to_string(i);
            if (s.find(x) != string::npos){
                cout << x;
                break;
            }
        }   
    }
    return 0;   
}