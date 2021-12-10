#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 1e9;
int n, sum[N], c[4 * N];
char s[N];

int query(int x){
    int least = INF;
    while (x > 0){
        least = min(least, c[x]);
        x -= x & -x;
    }
    return least;
}
void update(int x, int id){
    while (x <= 4 * n){
        c[x] =  min(c[x], id);
        x += x & -x;
    }
}

bool isVowel(int c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

void solve(){
    memset(c, 127, sizeof(c));
    cin >> s;
    n = strlen(s);
    sum[0] = 0;
    for (int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + (isVowel(s[i]) ? -1 : 2);
    }
    int longest = -INF;
    for (int i = 0; i <= n; i++){
        int val = sum[i] + n + 1;
        longest = max(longest, i - query(val));
        update(val, i);
    }

    if (longest <= 0){
        cout << "No solution\n";
        return ;
    }
    int cnt = 0;
    for (int i = 0; i + longest <= n; i++){
        if (sum[i + longest] >= sum[i]){
            cnt++;
        }
    }
    cout << longest << " " << cnt;
}

int main(){
    solve();
    return 0;
}