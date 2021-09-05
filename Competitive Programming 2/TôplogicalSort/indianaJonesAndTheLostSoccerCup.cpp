#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, m, visited[maxn], indeg[maxn], outdeg[maxn], mark[maxn];
vector <int> graph[maxn];

int dfs(int s, int p){
	mark[s] = visited[s] = 1;
	for (int i = 0; i < graph[s].size(); i++){
		if (p == 0){
			if (visited[graph[s][i]] == 1 || (visited[graph[s][i]] == 0 && dfs(graph[s][i], p) == -1)){
				return -1;
			}
		}
		else if (p == 1 && mark[graph[s][i]] == 0){
			dfs(graph[s][i], p);
		}
	}
	visited[s] = 2;
	if (p == 1){
		cout << s << " ";
	}
	return 0;
}

int main(){
	int c;
	cin >> c;
	while(c--){
		cin >> n >> m;
		int i, z, y, f = 0;
		z = y = n;
		for (int i = 1; i <= n; i++){
			indeg[i] = outdeg[i] = mark[i] = visited[i] = 0;
			graph[i].clear();
		}

		while(m--){
			int a, b;
			cin >> a >> b;
			graph[b].push_back(a);
			if (indeg[b] == 0){
				z--;
			}
			if (outdeg[a] == 0){
				y--;
			}
			indeg[b]++;
			outdeg[a]++;
		}
		for (int i = 1; i <= n; i++){
			if (visited[i] == 0 && dfs(i, 0) == -1){
				f = 1;
				break;
			}
		}

		if (f == 1){
			cout << "recheck hints\n";
		}
		else if (z != 1 || y != 1){
			cout << "missing hints\n";
		}
		else{
			for (int i = 1; i <= n; i++){
				mark[i] = 0;
			}
			for (int i = 1; i <= n; i++){
				if(mark[i] == 0){
					dfs(i, 1);
				}
			}
			cout << endl;
		}
	}
	return 0;
}