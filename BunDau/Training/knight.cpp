#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

void solve(){
	int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	bool check = false;
	for (int i = 0; i < 8; i++){
		int x = a + X[i];
		int y = b + Y[i];
		if (x >= 0 && y >= 0 && x == c && y == d){
			check = true;
			break;
		}
	}
	if (check){
		cout << "Yes";
	}

	else cout << "No";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}


