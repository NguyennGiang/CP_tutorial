#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n; 
	int a[2*n];
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a, a + 2*n);
	for (int i = 0; i < n; i++) cout << a[i] << " " << a[2*n -1 - i] << " ";
	cout << endl;	
}

int main(){
	fast_io
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0;
} 