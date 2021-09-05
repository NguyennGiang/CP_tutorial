#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
vector <int> course[maxn];
int indegree[maxn];
vector <int> result;

bool kahn(){
	queue <int> q;
	for (int i = 1; i <= n; i++){
		if (indegree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		result.push_back(u);
		for (int v : course[u]){
			indegree[v]--;
			if (indegree[v] == 0){
				q.push(v);
			}
		}
	}

	return result.size() == n;
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		course[a].push_back(b);
		indegree[b] ++;
	}
	if (!kahn()){
		printf("IMPOSSIBLE\n");
	}
	else {
		for (int i = 0; i < n; i++){
			printf("%d ", result[i]);
		}
	}
	return 0;
}