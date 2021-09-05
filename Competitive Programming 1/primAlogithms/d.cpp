#include <bits/stdc++.h>

using namespace std;

const int maxn = 403;

struct edge
{
	int u, v, w;
};

bool compare(edge a, edge b){
	return a.w < b.w;
}

vector <edge> e;
int par[maxn];

void makeSet(int n){
	for (int i = 0; i < n; i++){
		par[i] = i;
	}
}

int find(int x){
	if(par[x] != x){
		return par[x] = find(par[x]);
	}
	return par[x];
}

int Union(int x, int y){
	x = find(x);
	y = find(y);

	if (x != y){
		par[x] = y;
		return 1;
	}
	return 0;
}

int main(){
	int s, c, tmp;
	string str1, str2, home;

	while(1){
		cin >> s >> c;

		if(s == 0 && c == 0){
			break;
		}

		map <string, int> mp;
		for (int i = 0; i < s; i++){
			cin >> str1;
			mp[str1] = i;
		}

		for (int i = 0; i < c; i++){
			cin >> str1 >> str2 >> tmp;
			edge get;
			get.u = mp[str1];
			get.v = mp[str2];
			get.w = tmp;
			e.push_back(get);
		}

		cin >> home;

		makeSet(s);

		sort(e.begin(), e.end(), compare);

		int sz = int(e.size());
		int cnt = 0, max = 0;
		int groups = s;

		for (int i = 0; i < sz; i++){
			if (Union(e[i].u, e[i].v)){
				max += e[i].w;
				cnt++;
				groups --;
				if (cnt == s - 1){
					break;
				}
			}
		}
		if(groups > 1){
			cout << "Impossible\n";
		}
		else {
			cout << max << '\n';
		}
		e.clear();
	}
	return 0;
}