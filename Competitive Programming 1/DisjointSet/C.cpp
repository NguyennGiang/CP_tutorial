#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int par[N];
int id[N], a[N];

int find(int s){
	if (s != par[s]){
		return par[s] = find(par[s]);
	}
	return par[s];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 

	for (int tc = 1; tc <= t; tc++){
		int n, q;
		cin >> n >> q;
		cout << "Case " << tc << ":\n";

		for (int i = 0; i < N; i++){
			par[i] = id[i] = a[i] = 0;
		}

		for (int i = 1; i <= n; i++){
			int x; 
			cin >> x;
			if (!id[x]){
				par[i] = id[x] = i;
				a[i] = x;
			}
			else {
				par[i] = id[x];
			}
		}

		while(q--){
			int k; 
			cin >> k;

			if (k == 1){
				int x, y; 
				cin >> x >> y;

				if (x == y) continue;

				else {
					if (id[y] == 0) {
						id[y] = id[x];
						a[id[y]] = y;
					}
					else {
						par[id[x]] = id[y];
					}
					id[x] = 0;
				}
			}

			else {
				int x; 
				cin >> x; 
				int id = find(x);
				cout << a[id] << '\n';
			}
		}
 	}
 	return 0;
}