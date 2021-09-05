#include <bits/stdc++.h>

using namespace std; 

const int INF = 1e9;

vector <vector<int>> dist;

void floydWarshall(vector <vector <int>> &matrix,  int n){
	dist.assign(n + 1, vector <int> (n + 1, INF));

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (matrix[i][j] == -1){
				dist[i][j] = INF;
			}
			else dist[i][j] = matrix[i][j];
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (dist[i][k] == INF) continue;
			for (int j = 1; j <= n; j++){
				if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

}

void solve(int id){
	int n; 
	cin >> n; 
	vector <vector <int>> matrix(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> matrix[i][j];
		}
	}

	floydWarshall(matrix, n);

	cout << "Circuit Design #" << id << ": ";

	if (dist[1][2] == 0 || dist[1][2] == INF){
		cout << "Back to the drawing board"; 
	}
	else cout << "No more hedgehog troubles";

	cout << '\n'; 

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 
	for (int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;

}