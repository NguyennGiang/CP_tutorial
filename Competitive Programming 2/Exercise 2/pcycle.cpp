#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

const int N = 205;
int n, m;
bool g[N][N];
int energy[N][N];
vector <int> res;
void findElerCycle(int u, int curEnergy){
	for (int v = 1; v <= n; v++){
		if (g[u][v] && curEnergy + energy[u][v] >= 0){
			g[u][v] = false;
			g[v][u] = false;
			findElerCycle(v, curEnergy + energy[u][v]);	
		}
	}
	res.push_back(u);
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = 1;
		energy[a][b] = energy[b][a] = c;
	}
	int check = 0;
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = 1; j <= n; j++){
			cnt += g[i][j];
		}
		check += (cnt % 2);
	}
	if (check > 0){
		cout << -1;
		return 0;
	}
	findElerCycle(1, 0);

	reverse(res.begin(), res.end());
	for (int u : res){
		cout << u << " ";
	}
	return 0;
}	