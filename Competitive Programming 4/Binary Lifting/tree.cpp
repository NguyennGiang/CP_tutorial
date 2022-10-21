#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int N = 5e4 + 10;
int n;
int p[N][20];

void preprocess(){
	for (int j = 1; j < 20; j++){
		for (int i = 0; i < n; i++){
			if (p[i][j-1] != -1){
				p[i][j] = p[p[i][j-1]][j-1];
			}
			else p[i][j] = -1;
		}
	}
}

int get(int x, int k){
	for (int i = 20; i >= 0 && x != -1; i--){
		if ((1 << i) <= k){
			x = p[x][i];
			k -= 1 << i;
		}
	}
	return x;
}

void solve(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i][0];
	}
	preprocess();

	int x, k;
	while(cin >> x >> k){
		cout << get(x, k) << endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

