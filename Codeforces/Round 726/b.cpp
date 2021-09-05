#include <bits/stdc++.h>
#define pii pair <int, int>

using namespace std;

void solve(){
	int x, y, z, t; 
	cin >> x >> y >> z >> t;

	if (x == 1){
		if (t == 1){
			cout << x << " " << y << " " << x << " "<< y << '\n';
			return ;
		}
		if (t == y){
			cout << 1 << " " << 1 << " " << 1 << " "<< 1 << '\n';
			return ;
		}
		cout << 1 << " " << 1 << " " << x << " "<< y << '\n';
		return ;
	}
	if (y == 1){
		if (z == 1){
			cout << x << " " << y << " " << x << " "<< y << '\n';
			return ;
		}
		if (z == x){
			cout << 1 << " " << 1 << " " << 1 << " "<< 1 << '\n';
			return ;
		}
		cout << 1 << " " << 1 << " " << x << " "<< y << '\n';
		return ;
	}
	if ((z == 1 && t == 1) || (z == x && t == y)){
		cout << x << " " << 1 << " " << 1 << " " << y << '\n';
		return;
	}
	
	cout << 1 << " " << 1 << " " << x << " " << y << '\n';

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; 
	cin >> t; 
	while (t--){
		solve();
	}
	return 0;
}