#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <int>> graph;
vector <bool> visited;
vector <int> result; 

void dfs(int u){
	visited[u] = true;

	for (int v : graph[u]){
		if (visited[v] == false){
			dfs(v);
		}
	}
	result.push_back(u);
}

int main(){
	string s, ps;
	cin >> ps;

	graph.assign(26, vector <int> ());
	visited.assign(26, 1);

	for (int i = 0; i < ps.length(); i++){
		visited[ps[i] - 65] = 0;
	}

	while(ps != "#"){
		cin >> s;

		if(s == "#"){
			break;
		}

		for (char c : s){
			visited[c - 65] = 0;
		}
		for (int i = 0; i < s.length() && i < ps.length(); i++){
			if (s[i] != ps[i]){
				graph[ps[i] - 65].push_back(s[i] - 65);
				break;
			}
		}
		ps = s;
	}
	for (int i = 0; i < 26; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	for (int i = result.size() -1 ; i >= 0; i--){
		cout << char(result[i] + 65);
	}
	return 0;
}