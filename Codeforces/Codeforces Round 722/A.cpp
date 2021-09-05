#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std; 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; 
	cin >> t; 
	while(t--){
		int n; 
		cin >> n; 
		vector <int> v;
		for (int i = 0; i < n; i++){
			int num;
			cin >> num; 
			v.pb(num);
		}
		sort(v.begin(), v.end());
		int j = 0; 
		while(j < n){
			if (v[j] == v[0]){
				j++;
			}
			else {
				break;
			}
		}
		cout << n - j << '\n';
	}
	return 0;
	
}