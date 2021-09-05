#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    auto print = [&](int a, int b, int c, int d){
        printf("%d %d %d %d\n", ++a, ++b, ++c, ++d);
    };

    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zinID = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') zinID = i;
        }

        if (zinID == -1){
            print(0, n - 2, 1, n - 1);
        }
        else if (zinID < n / 2){
            print(zinID, n - 1, zinID + 1, n - 1);
        }
        else {
            print(0, zinID, 0, zinID - 1);
        }
    }
    return 0;
}