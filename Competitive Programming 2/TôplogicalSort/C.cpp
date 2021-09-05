#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int result;
vector <int> g[maxn];
int n, k;

int dfs(int cur, int par){
	int m = 0;
	for (int to : g[cur]){
		if (to == par) continue;
		m = max(m, dfs(to, cur));
	}
	m++;

	if (cur == 1 || par == 1) return 0;
	if (m < k) return m;
	result ++;
	return 0;
}
int main(){
	
	cin >> n >> k;

	vector <int> a;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		if (i == 0){
			if (t != 1){
				result ++;
			}
			continue;
		}
		g[t].push_back(i + 1);
		g[i+1].push_back(t);
	}
	dfs(1, -1);
	cout << result;
	return 0;
}