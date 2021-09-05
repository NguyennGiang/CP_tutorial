#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int const N = 1e5 + 5;
int n, m;
vector <int> graph[N];

void dfs(int u);

int count_ccs(){
	bool visited[n+1];
	int cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			cnt++;
			dfs(i);
		}
	}

	auto dfs = [](int u){
		visited[u] = true;

		for (int v : graph[u]){
			if (!visited[v]){
				dfs(v);
			}
		}
	};
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int num_ccs = count_ccs();
}