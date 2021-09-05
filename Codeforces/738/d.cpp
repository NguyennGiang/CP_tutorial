#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int findRoot(int u, int par[]){
	if (u != par[u]){
		return par[u] = findRoot(par[u], par);
	}
	return par[u];
}

void unionSet(int u, int v, int par[]){
	u = findRoot(u, par);
	v = findRoot(v, par);
	if (u == v){
		return;
	}
	par[u] = v;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	int par1[n + 1];
	int par2[n + 2];
	for (int i = 1; i <= n; i++){
		par1[i] = i;
		par2[i] = i;
	}

	for (int i = 0; i < m1; i++){
		int a, b;
		cin >> a >> b;
		unionSet(a, b, par1);
	}
	for (int i = 0; i < m2; i++){
		int a, b;
		cin >> a >> b;
		unionSet(a, b, par2);
	}

	vector <pair <int , int>> res;
	for (int i = 1; i <= n ; i ++){
		for (int j = i + 1; j <= n; j++){
			if ((findRoot(i, par1) != findRoot(j, par1)) && (findRoot(i, par2) != findRoot(j, par2))){
				unionSet(i, j, par1);
				unionSet(i, j, par2);
				res.push_back({i, j});
			}
		}
	}

	if (res.size() == 0){
		cout << 0;
	}
	else {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++){
			cout << res[i].first << " " << res[i].second << endl;
		}
	}
	return 0;
}