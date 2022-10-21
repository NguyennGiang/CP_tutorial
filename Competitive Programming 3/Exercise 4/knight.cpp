#include<bits/stdc++.h>
using namespace std;

int d[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

double solve(int r, int c, int n, int k, vector<vector<vector<double>>> &f){
	if(r >= n || c >= n || r < 0 || c < 0){
		return 0.0;
	}
	if (k == 0) return 1.0;
	if (f[k][r][c] != -1) return f[k][r][c];
	f[k][r][c] = 0;
	for (int i = 0; i < 8; i++){
		f[k][r][c] += solve(r + d[i][0], c + d[i][1], n, k - 1, f);
	}
	return f[k][r][c];
}

int main(){
	int n, k, r, c;
	cin >> n >> k >> r >> c;

	vector<vector<vector<double>>> f(k + 1, vector<vector<double>>(n, vector<double>(n, -1)));
	cout << solve(r, c, n, k, f) / pow(8, k) << endl;
	return 0;
}
