#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

const int N = 9;
const int M = 21;
int n, m;
pair <int, int> q[M];
int cost[M];

bool oce(vector <int> &a){
    for (int i = 0; i < m; i++){
        if (cost[i] > 0 && abs(a[q[i].f] - a[q[i].s]) > cost[i]){
            return false;
        }
        if (cost[i] < 0 && abs(a[q[i].f] - a[q[i].s]) < -cost[i]){
            return false;
        }
    }
    return true;
}

int main(){
    while (true){
        cin >> n >> m;
        
        if (!(n + m)){
            break;
        }

        vector <int> a(n);
        for (int i = 0; i < n; i++){
            a[i] = i;
        }

        for (int i = 0; i < m; i++){
            cin >> q[i].first >> q[i].second >> cost[i];
        }

        int res = 0;
        do {
            if (oce(a)) res++;
        } while(next_permutation(a.begin(), a.end()));
        
        cout << res << endl;
    }
    return 0;
}