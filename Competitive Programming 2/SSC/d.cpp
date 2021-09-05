#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
int price[N];
vector <int> graph[N];
int num[N], low[N];
bool found[N];
int counter;
stack <int> st;
ll nWays, total;

void dfs(int u){
	num[u] = low[u] = ++ counter;
	st.push(u);

	for (int v : graph[u]){
		if (!found[v]){
			if (num[v] > 0){
				low[u] = min (low[u], num[v]);
			}
			else {
				dfs(v);
				low[u] =  min (low[u], low[v]);
			}
		}
	}

	if (low[u] == num[u]){
		int mi = 1e9 + 7, cnt = 0;
		int v; 

		do {
			v = st.top();
			st.pop();
			found[v] = true;
			if (price[v] < mi){
				mi = price[v];
				cnt = 1;
			}
			else if (price[v] == mi){
				cnt++;
			}
		} while (u != v);
		total += mi;
		nWays = ((nWays % mod) * (cnt % mod)) % mod;
	}
}

void tarjan(){
	for (int i = 1; i <= n; i++){
		found[i] = false;
	}
	st = stack <int> ();
	for (int i = 1; i <= n; i++){
		if (!num[i]){
			dfs(i);
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> price[i];

	int m;
	cin >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	nWays = 1;
	tarjan();
	cout << total << " " << nWays;
	return 0;
}