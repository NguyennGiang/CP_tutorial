#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e5 + 5;
int n, q;
int par[maxn];
int w[maxn];

void makeSet(){

	for (int i = 1; i <= n; i++){
		par[i] = i;
		w[i] = i;
	}
}

int findSet(int s){
	if (s != par[s]){
		return par[s] = findSet(par[s]);
	}

	return par[s];
}

void unionSet(int s, int v){

	s = findSet(s);
	v = findSet(v);

	if (s == v) {
		return;
	}

	par[s] = v;
}
int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q; 

	makeSet();

	while (q--){
		int x; 
		cin >> x; 
		if (x == 1){
			int a, b; 
			cin >> a >> b; 
			unionSet(a, b);
		}

		if (x == 2){
			int a; 
			cin >> a;
			w[findSet(a)] = a;		
		}

		if (x == 3) {
			int a; 
			cin >> a; 
			cout << w[findSet(a)] << '\n';
		}

	}

	return 0;
}