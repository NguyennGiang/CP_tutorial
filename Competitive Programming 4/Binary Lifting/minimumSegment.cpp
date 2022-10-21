#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

const int N = 5e5 + 5;
int n, m, D;
int f[N][20];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

    cin >> n >> m;
    for (int i = 0, a, b; i < n; i++){
    	cin >> a >> b;
    	f[a][0] = max(f[a][0], b);
    	D = max(b, D);
    }

    for (int i = 1; i <= D; i++) f[i][0] = max(f[i][0], f[i-1][0]);
    //for (int i = 1; i <= D; i++) cout << f[i][0] << ' ';

    for (int j = 1; j < 20; j++){
    	for (int i = 0; i <= D; i++){
    		if(f[i][j-1] == -1) continue;
    		f[i][j] = f[f[i][j-1]][j-1];
    	}
    }

    while(m--){
    	int l, r;
    	cin >> l >> r;
    	int ans = 0;
    	for (int i = 19; i >= 0; i--){
    		if (f[l][i] < r){
    			l = f[l][i];
    			ans += 1 << i;
    		}
    	}

    	if (f[l][0] >= r) cout << ans + 1;
    	else cout << -1;
    	cout << endl;
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}