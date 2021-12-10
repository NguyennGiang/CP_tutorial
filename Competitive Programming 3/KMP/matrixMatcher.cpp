#include <bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long;
#define ull unsigned long long;

const int base1 = 131, base2 = 13331, N = 1e3 + 5;
int x, y, n, m;
char str[N][N], s[N][N];
unsigned long long hx[N][N], ans[N][N], p1[N], p2[N];

void solve(int t){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> str[i] + 1;
	}
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++){
		cin >> s[i] + 1;
	}
	int sum = 0;
	memset(hx, 0, sizeof(hx));
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			hx[i][j] = hx[i][j-1] * base1 + hx[i-1][j] * base2 - hx[i-1][j-1] * base1 * base2 + str[i][j] - 'a';
		}
	}
	for (int i = 1; i <= x; i++){
		for (int j = 1; j <= y; j++){
			ans[i][j] = ans[i][j-1] * base1 + ans[i-1][j] * base2 - ans[i-1][j-1] * base1 * base2 + s[i][j] - 'a';
		}
	}
	for (int i = x; i <= n; i++){
		for (int j = y; j <= m; j++){
			if (ans[x][y] == hx[i][j] - hx[i-x][j] * p2[x] - hx[i][j-y] * p1[y] + hx[i-x][j-y] * p1[y] * p2[x]){
				sum++;
			}
		}
	}
	cout << sum << endl;
}

int main(){

	KAMEHAMEHA

	int t; cin >> t;
	p1[0] = p2[0] = 1;
	for (int i = 1; i < N; i++){
		p1[i] = p1[i-1] * base1, p2[i] = p2[i-1] * base2;
	}
	while (t--){
		solve(t);
	}
	return 0;
}
