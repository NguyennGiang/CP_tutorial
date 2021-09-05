//DPT O(n + m);

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 805;
int n, m;
vector <int> g[N];
int indeg[N];
int componentID[N];
int componentCount;
int counter;
int low[N], num[N];
stack <int> st;
bool found[N];

void dfs(int u){

	low[u] = num[u] = ++counter;	
	st.push(u);

	for (int v : g[u]){
		if (!found[v]){
			if (num[v] > 0){
				low[u] = min (low[u], num[v]);
			}

			else {
				dfs(v);
				low[u] = min (low[u], low[v]);
			}
		}
	}

	if (low[u] == num[u]){
		int v;
		componentCount++;

		do{
			v = st.top();
			st.pop();
			componentID[v] = componentCount;
			found[v] = true;
		} while (u != v);
	} 
}

void tarjan(){
	counter = 0;

	for (int i = 1; i <= n; i++){
		if (!num[i]){
			dfs(i);
		}
	}
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int u , v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	tarjan();

	for (int i = 1; i <= n; i++){
		for (int j : g[i]){
			if (componentID[i] != componentID[j]){
				indeg[componentID[j]]++;
			}
		}
	}

	int res = 0;

	for(int i = 1; i <= componentCount; i++){
		if (indeg[i] == 0){
			res++;
		}
	}
	cout << res;
	return 0;
}