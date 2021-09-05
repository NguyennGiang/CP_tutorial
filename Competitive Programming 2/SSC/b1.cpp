// DPT O(M + N)
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define RASENGAN ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;

int const N = 1e5 + 5;
int n, m;
int low[N], num[N];
int counter, componentCount;
int componentID[N];
bool found[N];
stack <int> st;
vector <int> graph[N];
int degree[N];

void init(){
	for (int i = 1; i <= n; i++){
		graph[i].clear();
		num[i] = 0;
		low[i] = 0;
		st = stack <int> ();
		counter = 0;
		componentID[i] = 0;
		componentCount = 0;
		degree[i] = 0;
		found[i] = false;
	}
}

void dfs(int u){
	num[u] = low[u] = ++counter;
	st.push(u);

	for (int v : graph[u]){
		if (!found[v]){
			if (num[v] > 0){
				low[u] = min(low[u], num[v]);
			}
			else {
				dfs(v);
				low[u] = min(low[v], low[u]);
			}
		}
	}

	if (num[u] == low[u]){
		componentCount++;

		int v;
		do {
			v = st.top();
			st.pop();
			componentID[v] = componentCount;
			found[v] = 1;
		} while (v != u);
	}
}

void tarjan(){
	for (int i = 1; i <= n; i++){
		if (!num[i]){
			dfs(i);
		}
	}
}


int main(){
	
	RASENGAN;

	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		init();

		while (m--){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b); 
		}

		tarjan();

		for (int i = 1; i <= n; i++){
			for (int j : graph[i]){
				if (componentID[i] != componentID[j]){
					degree[componentID[j]]++;
				}
			}
		}

		int num_indeg = 0;

		for (int i = 1; i <= componentCount; i++){
			if (degree[i] == 0){
				num_indeg++;
			}
		}

		cout << num_indeg << '\n';
	}
	return 0;
}