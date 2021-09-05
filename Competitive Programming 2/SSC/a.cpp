// #include <iostream>
// #include <stack>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include <string>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int num[N], low[N];
bool found[N];
vector <int> graph[N];
unordered_map <string, int> convert;
int counter;
stack <int> st;
int n, m;
string s[30];

void dfs(int u){
	num[u] = low[u] = ++ counter;
	st.push(u);

	for (int v : graph[u]){
		if(!found[v]){
			if (num[v] > 0){
				low[u] = min(low[u], num[v]);
			}
			else {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
		}
	}

	if (num[u] == low[u]){
		int v;
		do {
			v = st.top();
			st.pop();
		//	cout << convert[v] << " ";
			if (v == u){
				cout << s[v];
			}
			else {
				cout << s[v] << ", ";
			}
			found[v] = true;
		} while(v != u);

		cout << '\n';

	} 
}

void tarjan(){
	counter = 0;
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
	
	int t = 1;
	while(1){
		cin >> n >> m;
		if (n == 0 && m == 0){
			break;
		}

		convert.clear();
		for (int i = 1; i <= n; i++){
			graph[i].clear();
			num[i] = 0;
			low[i] = 0;
		}

		int id = 0;
		while(m--){
			string to, ed;
			cin >> to >> ed;
			if (!convert[to]){
				convert[to] = ++ id;
			}
			if (!convert[ed]){
				convert[ed] = ++ id;
			}
			int x1 = convert[to];
			int x2 = convert[ed];

			s[x1] = to;
			s[x2] = ed;

			graph[convert[to]].push_back(convert[ed]);
		}

		cout << "Calling circles for data set " << t << ":\n";
		tarjan();
		t++;	
	}
}