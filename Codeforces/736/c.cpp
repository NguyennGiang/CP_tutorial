#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int outdeg[n+1] = {0};
	int ans = 0;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (u > v){
			swap(u, v);
		}
		outdeg[u]++;

		if (outdeg[u] == 1) ans++;
	}

	int q;
	cin >> q;

	while(q--){
		int t, u, v;
		cin >> t;
		if (t == 1){
			cin >> u >> v;
			if (u > v){
				swap(u, v);
			}
			outdeg[u]++;
			if (outdeg[u] == 1) ans++;
		}

		else if (t == 2){
			cin >> u >> v;
			if (u > v){
				swap(u, v);
			}
			outdeg[u]--;
			if (outdeg[u] == 0) ans--;
		}

		else cout << n - ans << endl;
	}
	return 0;
}