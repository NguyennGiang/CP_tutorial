#include <bits/stdc++.h>

using namespace std;

void solve(){
	int k, n, m;
	cin >> k >> n >> m;
	vector <int> a(n), b(m);
	for (auto &ai : a) cin >> ai;
	for (auto &bi : b) cin >> bi;

	vector <int> seg;
	
	int lines = k;
	int i = 0, j = 0;
	int curline;
	bool fail = false;
	while(i < n && j < m){
		if (a[i] == 0){
			seg.push_back(0);
			lines++;
			i++;
			continue;
		}
		else if (b[j] == 0){
			seg.push_back(0);
			j++;
			lines++;
			continue;
		}

		else if (a[i] < b[j]){
			curline = a[i];
			i++;
		}
		else{
			curline = b[j];
			j++;
		}
		if(curline <= lines){
			seg.push_back(curline);

		}
		else
		{
			fail = true;
			break;
		}
	}
	while(i < n){
		if (a[i] == 0){
			lines++;
			seg.push_back(0);
		}
		else if(a[i] <= lines){
			seg.push_back(a[i]);
		}
		else {
			fail = true; 
			break; 
		}
		i++;
	}
	while(j < m){
		if (b[j] == 0){
			lines++;
			seg.push_back(0);
		}
		else if(b[j] <= lines){
			seg.push_back(b[j]);
		}
		else {
			fail = true; 
			break; 
		}
		j++;
	}
	if (fail){
		cout << -1 << '\n';
	}
	else {
		for (int i : seg){
			cout << i << " ";
		}
		cout << '\n';
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}