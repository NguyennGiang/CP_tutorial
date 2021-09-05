#include <bits/stdc++.h>
#define pb push_back

using namespace std; 

const int N = 100005;

//count of all adjacent side
int  degree[N];

bool found[N];

//connected component of the graph
vector <int> curr_graph;

//adjacency list
vector <vector <int>> adj_list;

//check tree?
// bool checkTree = false;
int x = 0; // numbers of adj 
int y = 0; // y/2 numbers of edges

// fuction to add an edge in the graph
void addEdges(int u, int v){
	adj_list[u].pb(v);
	adj_list[v].pb(u);
	degree[u]++;
	degree[v]++;
}

// Dfs
void Dfs(int u){
	y += adj_list[u].size();
	x += 1;
	found[u] = true; 
	curr_graph.pb(u);
	for (int it : adj_list[u]){
		if(!found[it]){
			Dfs(it);
		}
	}
	
}

pair <int, int> count(int n, int m){
	// count of cycle graph
	pair <int ,int> cnt = {0, 0}; 
	for (int i = 1; i <= n; i++){
		if (!found[i]){
			curr_graph.clear();
			Dfs(i);

			int flag = 1; 
			for (int v : curr_graph){
				if (degree[v] == 2) continue;
				else {
					flag = 0; 
					break; 
				}
			}
			if (flag == 1){
				cnt.second++;  // number of cycle 
			}
			if ((2*x - 2) == y){
				cnt.first++;    // number of tree
				
			}
			x = 0; 
			y = 0;
		}
	}
	return cnt;
}


int main(){
	int t; 
	cin >> t; 
	while (t--){
		memset(degree, 0, sizeof(degree));
		memset(found, false, sizeof(found));
		curr_graph.clear();
		adj_list.assign(N, vector <int> ());
		int n, m; 
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			int u, v; 
			cin >> u >> v; 
			addEdges(u, v);
		}
		pair <int, int> cnt = count(n, m);
		cout << cnt.first << " " << cnt.second << endl; 
	}
	return 0; 
}