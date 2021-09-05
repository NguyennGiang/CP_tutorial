//DPT O(N + M)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

int n, m;
int componentCount[2];
int componentID[2][N];
int degree[N];
bool visited[2][N];
vector<int> orders;
vector<int> Graph[N], reverseGraph[N];

void dfs1(int u){
	visited[0][u] = true;
	componentID[0][u] = componentCount[0];

	for (int v : reverseGraph[u]){
		if (!visited[0][v]){
			dfs1(v);
		}
	}
	orders.push_back(u);
}

void dfs2(int u){
	visited[1][u] = true;

	componentID[1][u] = componentCount[1];

	for (int v : Graph[u]){
		if (!visited[1][v]){
			dfs2(v);
		}
	}
}
int main(){
	cin >> n >> m;

	while (m--){
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		reverseGraph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++){
		if (!visited[0][i]){
			componentCount[0]++;
			dfs1(i);
		}
	}

	reverse(orders.begin(), orders.end());
	// for (int i : orders) cout << i << " ";

	for (int i : orders){
		if (!visited[1][i]){
			componentCount[1]++;
			dfs2(i);
		}
	}

	// for (int i = 1; i <= n; i++){
	// 	cout << i << " -->" << componentID[1][i] << endl;
	// }

	for (int i = 1; i <= n; i++){
		for (int j : reverseGraph[i]){
			if(componentID[1][i] != componentID[1][j]){
				degree[componentID[1][j]]++;
			}
		}
	}

	int starting = 0;

	for (int i = 1; i <= componentCount[1]; i++){
		cout << degree[i] << " ";
		if (!degree[i]){
			starting++;
		}
	}

	if (starting > 1){
		cout << 0;
		return 0;
	}

	else {
		vector <int> result;

		for (int i = 1; i <= n; i++){
			if (!degree[componentID[1][i]]){
				result.push_back(i);
			}
		}

		cout << result.size() << '\n';

		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
	}
	return 0;
}