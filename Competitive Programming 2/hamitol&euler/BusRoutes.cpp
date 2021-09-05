// DPT O(N*N);
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], indeg[N], outdeg[N];
int deg[N][N];
vector <int> res;

void findEuler(int u){
    for (int v = 0; v < N; v++){
        if (deg[u][v] > 0){
            deg[u][v]--;
            outdeg[u]--;
            indeg[v]--;
            findEuler(v);
        }
    }
    res.push_back(u);
}

int main(){
    int t;
    cin >> t;
    int num = 0;
    while(t--){
        int m;
        cin >> m;
        num += m;
        for (int i = 0; i <= m; i++){
            cin >> a[i];
            if (i){
                indeg[a[i]]++;
                outdeg[a[i-1]]++;
                deg[a[i-1]][a[i]]++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if (indeg[i] != outdeg[i]){
            cout << 0;
            return 0;
        }
    }
    findEuler(1);
    if (res.size() - 1 != num){
        cout << 0;
    }
    else {
        cout << num;
        reverse(res.begin(), res.end());
        for (int i : res){
            cout << " " << i;
        }    
    }
    return 0;
}