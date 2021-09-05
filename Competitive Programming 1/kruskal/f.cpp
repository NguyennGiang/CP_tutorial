#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define RASENGAN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int N = 205;
const int M = 50005;
const ll INF = 1e15;

ll ans = INF;
int n, m, g, s;
int par[N];

struct edge
{
	int u, v;
	ll wg, ws;
};

edge e[M], stc[M];

bool compare (edge xx, edge yy){
	if(xx.wg != yy.wg){
		return xx.wg < yy.wg;
	}
	return xx.ws < xx.ws;
}

void init()
{
	for (int i = 1; i <= n; i++){
		par[i] = i;
	}
}

int find(int x){
	if (x != par[x]){
		return par[x] = find(par[x]);
	}
	return par[x];
}

void kruskal(){
	int tt = 0;
	
	for (int i = 0; i < m; i++){
		init();
		stc[tt++] = e[i];
		ll maxx = -INF;
		for (int j = tt - 1; j >= 1; j--){
			if (stc[j].ws < stc[j-1].ws){
				swap(stc[j], stc[j-1]);
			}
		}
		int hav = 0;
		for (int j = 0; j < tt; j++){
			int u = find(stc[j].u);
			int v = find(stc[j].v);
			if (u != v){
				maxx = max(maxx, stc[j].ws);
				stc[hav++] = stc[j];
				par[u] = v;
			}
			if (hav == n - 1) break;
		}

		if (hav == n - 1){
			ans = min(ans, e[i].wg * g + maxx* s);
		}
		tt = hav;
	}
}

int main(){
	
	cin >> n >> m;
	cin >> g >> s;

	for (int i = 0; i < m; i++){
		cin >> e[i].u >> e[i].v >> e[i].wg >> e[i].ws;
	}
	sort(e, e+m, compare);

	kruskal();

	if (ans == INF){
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}