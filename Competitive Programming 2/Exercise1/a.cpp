#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector <int> g[N];
int indegree[N];
int n, m;
int ways[N];

void topo(){
	queue <int> q;

	for (int i = 2; i <= n; i++){
		if (indegree[i] == 0){
			q.push(i);
		}
	}

	q.push(1);
	ways[1] = 1; 

	while(!q.empty()){
		int u = q.front();

		q.pop();

		for (int v : g[u]){
			indegree[v]--;

			if (indegree[v] == 0){
				q.push(v);
			}

			ways[v] += ways[u];
			ways[v] %= mod;
		}
	}
}

int main(){
	cin >> n >> m;

	while(m--){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		indegree[v]++;
	}

	topo();

	cout << ways[n];
	return 0;
}