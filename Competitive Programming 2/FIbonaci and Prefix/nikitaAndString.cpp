#include <bits/stdc++.h>
using namespace std;

int aa[5005], bb[5005];

int main(){
    string s;
    cin >> s;
    s = " " + s;
    int n = s.length();

    for (int i = 1; i < n; i++){
        if (s[i] == 'a'){
            aa[i] ++;
        }
        else bb[i]++;
    }
    for (int i = 1; i <= n; i++){
        aa[i] += aa[i-1];
        bb[i] += bb[i-1];
    }
    int answer = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            // aaaaa(j - i)aaaaaa
            int a = aa[n] - aa[j] + aa[i];
            int b = bb[j] - bb[i];
            answer = max(answer, a + b);
        }
    }
    cout << answer << endl;
    return 0;
}