#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
const int maxn = 305;
int n, m, k;

char a[maxn][maxn];
bool used[maxn][maxn];
pii par[maxn][maxn];

void makeSet(){
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			par[i][j] = {i, j};
		}
	}
}

pii findSet(pii x){

	if (x != par[x.fi][x.se]){
		return par[x.fi][x.se] = findSet(par[x.fi][x.se]);
	}
	return par[x.fi][x.se];
}

void unionSet(pii x, pii y){
	x = findSet(par[x.fi][x.se]);
	y = findSet(par[y.fi][y.se]);

	if(x == y){
		return;
	}
	par[y.fi][y.se] = {x.fi, x.se};

}
bool checkBlackCell(){
	for (int i = 1; i <= n ; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] == '#' && a[i][j+1] == '#' && a[i+1][j] == '#' && a[i+1][j+1] == '#'){
				return false;
			}
		}
	}
	
	makeSet();

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j] == '.'){
				continue;
			}

			if (i + 1 <= n && a[i+1][j] == '#'){
				unionSet(mp(i, j), mp(i+1, j));
			}

			if (i - 1 >= 1 && a[i-1][j] == '#') {
				unionSet(mp(i-1, j), mp(i, j));
			}

			if (j + 1 <= m && a[i][j+1] == '#') {
				unionSet(mp(i, j), mp(i, j+1));
			}

			if (j - 1 >= 1 &&  a[i][j-1] == '#') {
				unionSet(mp(i, j), mp(i, j-1));
			}
		}
	}

	int island = 0;
	pii x = {0, 0};

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '#') {
				if (findSet(mp(i, j)) != x){
					island++;
					x = findSet(mp(i, j));
				}
			}
		}
	}

	if (island > 1) {
		return false;
	}
	return true;

}

bool bfs(int r, int c, int v){
	queue <pair <int, int>> q;

	q.push({r, c});
	used[r][c] = true;

	int cnt = 0;

	while(!q.empty()) {

		pair <int , int> u = q.front();
		q.pop();

		int i = u.fi;
		int j = u.se;

		for (int k = 1; k + j <= m; k++){
			if (!used[i][j+k]){
				used[i][j+k] = true;
				q.push({i, j + k});
			}
			else {
				break;
			}
		}

		for (int k = 1; k + i <= n; k++){
			if (!used[i+k][j]){
				used[i+k][j] = true;
				q.push({i+k, j});
			}
			else {
				break;
			}
		}

		for (int k = 1; i - k >= 1; k++){
			if(!used[i-k][j]){
				used[i-k][j] = true;
				q.push({i-k, j});
			}
			else {
				break;
			}
		}

		for (int k = 1; j - k >= 1; k++){
			if (!used[i][j-k]){
				used[i][j-k] = true;
				q.push({i, j-k});
			}
			else {
				break;
			}
		}

		cnt++;

	}

	if (cnt != v){
		return false;
	}
	return true;

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 

	for (int tc = 1; tc <= t; tc++){

		cin >> n >> m >> k;

		memset(a, '.', sizeof(a));
		memset(used, true, sizeof(used));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];

				if (a[i][j] == '.') {
					used[i][j] = false;
				}
				
			}
		}

		bool oce = checkBlackCell();
		bool nurikabe = true;

		cout << "Puzzle #" << tc << ": ";
		if(!oce) {
			nurikabe = false;
			//cout << "here\n";
		}

		while(k--){
			int r, c, v;
			cin >> r >> c >> v;

			if (!nurikabe) continue;
			else {
				nurikabe = bfs(r, c, v);
				//cout << nurikabe << endl;
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (!used[i][j]){
					nurikabe = false;
					break;
				}
			}
		}

		if(!nurikabe){
			cout << "Incorrect\n";
		}
		else {
			cout << "Correct\n";
		}
	}
	return 0;
}