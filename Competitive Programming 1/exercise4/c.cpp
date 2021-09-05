#include <iostream>
#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;
const int maxn = 1005;
int r, c;
int go[maxn][maxn];
char tmp[maxn];
bool mp[maxn][maxn], vis[maxn][maxn];
int mark = 0;
pii nei[4] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

void dfs(int i, int j){

	go[i][j] = mark;
  vis[i][j] = 1;
	
	for (int k = 0; k < 4; k++){
		int u = i + nei[k].fi;
		int v = j + nei[k].se;
		if (u > r || v > c || u < 1 || v < 1){
			continue;
		}
		if (mp[i][j] == mp[u][v] && !vis[u][v]){
			dfs(u, v);
		}
	}
	
}

int main(){

	cin >> r >> c;
	//getchar();
	for (int i = 1; i <= r; i++){
		scanf("%s", tmp + 1);
		for (int j = 1; j <= c; j++){
			mp[i][j] = (tmp[j] == '1');
		}
	}

	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			if (!vis[i][j]){
				++mark;
				dfs(i, j);
			}
		}
	}

	int m;
	cin >> m;
	// for (int i = 1; i <= r; i++){
	// 	for (int j = 1; j <= c; j++){
	// 		cout << go[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	while(m--){
		int i, j, u, v;
		cin >> i >> j >> u >> v;
		if (go[i][j] == go[u][v]){
			cout << (mp[i][j] == 1 ? "decimal\n" : "binary\n");
		}
		else {
			cout << "neither\n";
		}
	}
	return 0;
}