/*
	--> MUABI (Chuyên tin Lê Hồng Phong 2018-2019)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

int main(){
	int n, m;
	cin >> n >> m;
	vector <pii> v;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({b, a});
	}

	sort(v.begin(), v.end(), greater<pii>());

	int res = 0;
	int id = 0;
	int cnt = 0;
	while (cnt < n && id < m){
		v[id].se = min(v[id].se, n - cnt);
		res += v[id].fi * v[id].se;
		cnt += v[id].se;
		id++;
	}
	cout << res;
	return 0;
}