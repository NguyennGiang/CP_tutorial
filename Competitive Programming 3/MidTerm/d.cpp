#include <bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 1e6 + 5;
char s3[2 * N];
string s1, s2;
int p[2 * N];
int stp[N];
int h1[N], h2[N], h1r[N], h2r[N];

int get1(int x, int l){
    return h1[x] - h1[x + l] * stp[l];
}

int get2(int x, int l){
    return h2[x] - h2[x + l] * stp[l];
}

int get1r(int x, int l){
    return h1r[x] - h1r[x + l] * stp[l];
}

int get2r(int x, int l){
    return h2r[x] - h2r[x + l] * stp[l];
}

int main(){
    KAMEHAMEHA;

    // gets(s1);
    // gets(s2);
    getline(cin, s1);
    //getchar();
    getline(cin, s2);
    if (s1.length() != s2.length()){
        cout << "-1 -1";
        return 0;
    }

    int n = s1.length();
    s3[n] = 1;

    for (int i = 0; i < n; i++){
        s3[i] = s1[n - i - 1];
        s3[i + n + 1] = s2[i];
    }

    //cout << s3 << endl;
    int k = 0;

    for (int i = 1; i <= 2 * n; i++){
        while (k > 0 && s3[k] != s3[i]){
            k = p[k-1];
        }
        if (s3[i] == s3[k]) k++;
        p[i] = k;
    }

    stp[0] = 1;
    for (int i = 1; i <= n; i++){
        stp[i] = stp[i-1] * 239;
    }

    h1[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        h1[i] = h1[i + 1] * 239 + s1[i];
    }

    h2[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        h2[i] = h2[i+1] * 239 + s2[i];
    }

    h1r[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        h1r[i] = h1r[i + 1] * 239 + s1[n - i - 1];
    }

    h2r[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        h2r[i] = h2r[i + 1] * 239 + s2[n - i - 1];
    }

    int l, r, m;
    int ans1 = -1, ans2 = 1e9;

    for (int i = 1; i <= n; i++){
        if (get1(0, i) == get2r(0, i)){
            int l = 0;
            int r = n - i;
            while (l < r){
                m = (l + r + 1) / 2;
                if (get1(i, m) == get2(0, m)){
                    l = m;
                }
                else r = m - 1;
            }
            if (p[2 * n - i] > 0 && p[2 * n - i] + l >= n - i){
                if (ans1 < i - 1 || ((ans1 == i) && (ans2 > n - p[2 * n - i]))){
                    ans1 = i - 1;
                    ans2 = n - p[2 * n - i];
                }
            }
        }
    }

    if (ans1 == -1){
        cout << "-1 -1";
    }    
    else {
        cout << ans1 << " " << ans2;
    }
    return 0;
}