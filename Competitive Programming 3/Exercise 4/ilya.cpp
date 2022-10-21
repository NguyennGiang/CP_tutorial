#include<bits/stdc++.h>
using namespace std;

int n, t;
double p;
double f[2005][2005];

void solve(){
	cin >> n >> p >> t;
	cout << fixed << setprecision(6);

	f[0][0] = 1;
	for (int i = 1; i <= t; i++){
		for (int j = 0; j <= n; j++){
			if (j == n){
				f[i][j] += f[i-1][j];
			}
			else f[i][j] += f[i-1][j] * (1 - p);
			if (j > 0) f[i][j] += f[i-1][j-1] * p;
		}
	}
	double ans = 0.0;
	for (int i = 0; i <= n; i++){
		ans += f[t][i] * i;
	}
	cout << ans << endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	return 0;
}
