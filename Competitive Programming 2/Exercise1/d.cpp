#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

typedef pair <int ,int> pii;
const int N = 21;
int n, m, z;
pii st, ed;
char matrix[N][N];
bool vis[N][N];

bool isSafe(int i, int j){
	if (i >= 0 && j >= 0 && matrix[i][j] != '#' && i < n && j < m){
		return true;
	}
	return false;
}

bool solve(int i, int j, int gold){
	if (gold > z){
		return false;
	}
	if (i == ed.f && j == ed.s && gold == z){
		return true;
	}

	if (isSafe(i, j)){
		if (vis[i][j] == true){
			return false;
		}
		else {
			vis[i][j] = true;
			int curGold = gold;

			if (matrix[i][j] == 's'){
				curGold++;
			}

			// down 
			if (solve(i + 1, j, curGold) == true){
				return true;
			}

			// up
			if (solve(i - 1, j, curGold) == true){
				return true;
			}

			// right
			if (solve(i, j + 1, curGold) == true){
				return true;
			}

			// left
			if (solve(i, j - 1, curGold) == true){
				return true;
			}

			vis[i][j] = false;
			curGold = gold;
			return false;
		}
	}
	return false;
}	

int main(){
	cin >> n >> m >> z;

	memset(vis, false, sizeof (vis));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> matrix[i][j];
			if (matrix[i][j] == '@'){
				st.f = i;
				st.s = j;
 			}

 			if (matrix[i][j] == 'x'){
 				ed.f = i;
 				ed.s = j;
 			}
		}
	}
	int gold = 0;

	bool oce = solve(st.f, st.s, gold);

	if (oce){
		cout << "SUCCESS";
	}
	else {
		cout << "IMPOSSIBLE";
	}
	return 0;
}