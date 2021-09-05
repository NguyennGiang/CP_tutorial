#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector <int>> dist;

void floydWarshall(vector <vector <int>> &matrix, int n){
	dist.assign(n + 1, vector <int>(n + 1, INF));

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dist[i][j] = (i == j? 0 : matrix[i][j]);
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (dist[i][k] >= INF) continue;
			for (int j = 1; j <= n; j++){
				if (dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

}

void solve(int tc){
	int n, m; 
	cin >> n >> m; 
	vector <vector <int>> matrix(n + 1, vector<int> (n + 1, INF));
	vector <int> weight;
	vector <int> Us;
	vector <int> Vs;
	for (int i = 0; i < m; i++){
		int u , v, w; 
		cin >> u >> v >> w; 
		matrix[u][v] = min(w, matrix[u][v]);
		matrix[v][u] = matrix[u][v];
		weight.push_back(w);
		Us.push_back(u);
		Vs.push_back(v);

	}

	floydWarshall(matrix, n);

	bool oce = true;
	for (int i = 0; i < m; i++){
		if (dist[Us[i]][Vs[i]] != weight[i])
		{
			oce = false;
		}
	}

	cout << "Case #" << tc << ": ";

	if (!oce){
		cout << "Impossible\n";
	}
	else{
		cout << m << "\n";
		for (int i = 0; i < m; i++){
			cout << Us[i] << " " << Vs[i] << " "  << weight[i] << '\n';
		}

	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 
	for (int id = 1; id <= t; id++){
		solve(id);
	}
	return 0;
}