#include <bits/stdc++.h>

using namespace std;


vector <vector <int>> adj;
vector <int> visited;


bool DFS(int s){
	visited[s] = 1; 

	for (int i = 0; i < adj[s].size(); i++){
		int v = adj[s][i];

		if(visited[v] == 1) {
			visited[v] = 2; 
			return true;
		}
		else {
			if(DFS(v)) return true;
		}
	}
	return false; 
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; 
	cin >> t; 
	for (int tc = 1; tc <= t; tc++){

		int n;
		cin >> n; 
		adj.assign(n + 1, vector<int>());
		

		for(int u = 1; u <= n; u++){
			int m;
			cin >> m;
			for (int j = 0; j < m; j++){
				int v; 
				cin >> v; 
				adj[u].push_back(v);

			}
		}

		int oce = 0;

		for (int i = 1; i <= n; i++){
			
			visited.assign(n + 1, 0);

			oce = DFS(i);
			if (oce == 1){
				break;
			}
		}

		cout << "Case #" << tc << ": ";
		if (oce == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}