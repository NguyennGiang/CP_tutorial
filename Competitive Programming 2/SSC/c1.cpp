#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
stack <int> st;
vector <int> graph[100005];
bool found[100005];
int low[100005], num[100005];
int counter;
int id;
int componentID[100005];
int indeg[100005];
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
				low[u] = min(low[u], low[v]);
			}
		}
	}
	if (low[u] == num[u]){
		id++;
		int v; 
		do {
			v = st.top();
			st.pop();
			componentID[v] = id;
			found[v] = true;
		} while (v != u);
	}
}

void tarjan(){
	counter = 0;
	id = 0;
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
	cin >> n >> m ;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	tarjan();

	for (int i = 1; i <= n; i++){
		for (int j : graph[i]){
			if (componentID[i] != componentID[j]){
				indeg[componentID[j]]++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= id; i++){
		//cout << indeg[i] << " ";
		if (indeg[i] == 0){
		//	cout << i << " ";
			ans++;
		}
	}
//	cout << '\n' << ans << " " << id << endl;
 	if (ans > 1){
		cout << 0;
		return 0;
	}
	else {
		vector <int> result;
		for (int i = 1; i <= n; i++){
			if (indeg[componentID[i]] == 0){
				result.push_back(i);
			}
		}
		cout << result.size() << '\n';

		for (int i : result){
			cout << i << " ";
		}
	}
	return 0;

	for (int i = 1; i <= n; i++){
		cout << i << " --> " << componentID[i] << endl;
	}
}
