#include <bits/stdc++.h>

using namespace std;

const int N = 18;
char str[N], sol[N];
int qtt[10], u, n;

bool solve(int id, int less){
    if (id == n){
        return 1;
    }

    sol[u] = 0;

    for (int i = less ? str[id] : '9'; i >= '0'; i--){
        if (qtt[i - '0'] == 2) continue;

        qtt[i - '0']++;
        if (i != '0' || u != 0) sol[u++] = i;
        if (solve(id + 1, i == str[id] ? less : 0)) return 1;
        u--;
        qtt[i - '0']--;
    }
    return 0;
}

int main(){
    while(cin >> str){
        memset(qtt, 0, sizeof qtt);
        n = strlen(str);
        u = 0;
        solve(0, 1);
        sol[u] = 0;
        cout << sol << '\n';
    }
    return 0;
}