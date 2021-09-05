#include <bits/stdc++.h>
using namespace std; 

void solve(){
	int n; 
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int flag = 1;
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			flag = 0;
			break;
		}
	} 
	int max = a[0];
	for (int i = 0; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	//cout << max << endl;
	if (flag == 0){
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		cout << max + 1 << '\n';
		for (int i = 0; i <= max; i++){
			cout << i << " ";
		}
		cout << endl;
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