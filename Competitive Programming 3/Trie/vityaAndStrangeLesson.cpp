#include<bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

const int N = 1e7;
int n, m;
int tree[N][2];
int a[N];
int val[N];
int num;

void insert(int x){
    int u = 0;
    for (int i = 25; i >= 0; i--){
        int c = (x >> i) & 1;
        if (!tree[u][c]){
            tree[u][c] = num++;
        }
        u = tree[u][c];
    }
    val[u] = x;
}

int find(int x){
    int u = 0;
    for (int i = 25; i >= 0; i--){
        int c = (x >> i) & 1;

        if (tree[u][c]){
            u = tree[u][c];
        }
        else u = tree[u][c ^ 1];
    }
    return val[u];
}

int main(){
    KAMEHAMEHA

    cin >> n >> m;
    num = 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x] = 1;
    }

    for (int i = 0; i <= 600000; i++){
        if (!a[i]){
            insert(i);
        }
    }
    int sw = 0;
    while(m--){
        int x; cin >> x;
        sw ^= x;
        cout << (find(sw) ^ sw) << endl;
    }
    return 0;
}


