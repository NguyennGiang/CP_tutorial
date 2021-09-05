#include <bits/stdc++.h>

using namespace std;

const int 
		n = 7,
		m = 8;
int ways;
int matrix[n][m];
bool mark[n][m], used[n][m];

void solve(int x, int y){
	if (y == m){
		y = 0; 
		x++;
	}

	if (x == n){
		ways++;
		return;
	}

	if (mark[x][y]){
		solve(x, y + 1);
	}
	else {
		mark[x][y] = 1;
		// right
		if (y < m - 1 && !mark[x][y+1] && !used[matrix[x][y]][matrix[x][y+1]]){
			used[matrix[x][y]][matrix[x][y+1]] = 1;
			mark[x][y+1] = 1;
			used[matrix[x][y+1]][matrix[x][y]] = 1;
			solve(x, y + 1);
			used[matrix[x][y]][matrix[x][y+1]] = 0;
			mark[x][y+1] = 0;
			used[matrix[x][y+1]][matrix[x][y]] = 0;
		}

		// donw
		if (x < n - 1 && !mark[x+1][y] && !used[matrix[x][y]][matrix[x+1][y]]){
			used[matrix[x][y]][matrix[x+1][y]] = 1;
			used[matrix[x+1][y]][matrix[x][y]] = 1;
			mark[x+1][y] = 1;
			solve(x, y + 1);
			used[matrix[x][y]][matrix[x+1][y]] = 0;
			used[matrix[x+1][y]][matrix[x][y]] = 0;
			mark[x+1][y] = 0;
		}
		mark[x][y] = 0;
	}
}

int main(){
	int t;
	cin >> t;

	while(t--){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		ways = 0;
		solve(0, 0);
		cout << ways << '\n';
	}
	return 0;
}