#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
double g[55][55];
int used[55][55], x[55], y[55];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; 

	while(1){
		cin >> n >> m; 

		if(!n && !m){
			break;
		}

		else {
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					g[i][j] = 1e+10; used[i][j] = 0;
				}
				g[i][i] = 0;
			}

			for (int i = 1; i <= n; i++){
				cin >> x[i] >> y[i];
			}

			for (int i = 1; i <= m; i++){
				int u, v; 
				cin >> u >> v; 
				g[u][v] = g[v][u] = hypot(x[u] - x[v], y[u] - y[v]);
				used[u][v] = used[v][u] = 1;
			}

			// floyd - warshall

			for (int k = 1; k <= n; k++){
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= n; j++){
						g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
					}
				}
			}

			double ret = 0; 

			int rx = -1, ry = -1;

			for (int i = 1; i <= n; i++){
				for (int j = i + 1; j <= n; j++){
					if (used[i][j]) continue;

					double d = hypot(x[i] - x[j], y[i] - y[j]), cuv = 0;
					//cout << d << '\n';
					for (int p = 1; p <= n; p++){
						for (int q = p + 1; q <= n; q++){
							cuv += g[p][q] - min(g[p][q], min(g[p][i] + g[j][q] + d, g[p][j] + g[i][q] + d));
							//cout << p << " " << q << " " << cuv << endl;
						}
					}

					if (cuv > 0 && cuv > ret + 1e-10){
						ret = cuv;
						rx = i; 
						ry = j;
					}
				}
			}

			if (ret > 1e-8){
				cout << rx << " " << ry << '\n';
			}
			else {
				cout << "No road required\n";
			}
		}
	}

	return 0;	
}