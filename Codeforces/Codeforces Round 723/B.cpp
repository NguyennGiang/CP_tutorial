#include <bits/stdc++.h>
# 
using namespace std; 

void solve(){
	int n; 
	cin >> n;
	int flag = 0; 
	for (int i = 0; i < 11; i++){
		if(111 * i <= n && (n - 111 * i) % 11 == 0){
			flag = 1;
			break;
		}
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}