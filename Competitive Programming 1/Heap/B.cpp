#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define pii pair <int , int>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std; 

int main(){
	fast_io
	int t; 
	cin >> t; 
	while(t--){
		int n; 
		cin >> n;
		vector <pii> arr; 
		for (int i = 0; i < n; i++){
			int a, b; 
			cin >> a >> b; 
			arr.pb(make_pair(a, b));
		}
		int l, p; 
		cin >> l >> p; 
		for (int i = 0; i < n; i++){
			arr[i].fi = l - arr[i].fi;
		}
		sort(arr.begin(), arr.end());
		// for (int i = 0; i< n; i++){
		// 	cout << arr[i].fi << " " << arr[i].se << endl;
		// }
		priority_queue <int> max;
		int step = 0; 
		for (int i = 0; i < n; i++){
			if(p >= arr[i].fi){
				max.push(arr[i].se);
			}
			else{
				while(!max.empty() && p <= arr[i].fi && p < l){
					p += max.top();
					max.pop();
					step++;
					//cout << p << endl;
				}
				if (p >= arr[i].fi){
					max.push(arr[i].se);
				}
			}
		}
		while(!max.empty() && p < l){
			p += max.top();
			max.pop();
			step++;
		}
		if (p < l){
			cout << -1 << endl;
		}
		else {
			cout << step << endl;
		}
	}
	return 0;
}