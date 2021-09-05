#include <bits/stdc++.h>

using namespace std; 

const int INF = 1e9;

int n, m, q; 
vector <vector <int>> dist;

void floydWarshall(vector<vector<int>> &maxtrix){
	dist.assign(n, vector <int> (n));

	for (int i = 0 ; i < n; i++){
		for (int j = 0; j < n; j++){
			dist[i][j] = (i == j ? 0 : maxtrix[i][j]);
		}
	}

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			if (dist[i][k] >= INF) continue;
			for (int j = 0; j < n; j++){
				if (dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// check negative cycle

	for (int i = 0;i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; dist[i][j] != -INF && k < n; k++)
					if (dist[k][k] < 0 && dist[i][k] != INF && dist[k][j] != INF)
						dist[i][j] = -INF;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(1){
		cin >> n >> m >> q;
		vector <vector <int>> matrix(n, vector<int>(n, INF));
		
		if(m == 0 && n == 0 && q == 0){
			break;
		}
		else{
			for (int i = 0; i < m; i++){
				int u, v ,w; 
				cin >> u >> v >> w; 
				matrix[u][v] = (w < matrix[u][v] ? w : matrix[u][v]);
			}	
			floydWarshall(matrix);
		}
		for (int i = 0; i < q; i++){
			int u, v; 
			cin >> u >> v; 
			if(dist[u][v] == INF){
				cout << "Impossible\n";
			}
			else if (dist[u][v] == -INF) cout << "-Infinity\n";
			else cout << dist[u][v] << '\n';

		}
		cout << '\n';
	}
	return 0;
}