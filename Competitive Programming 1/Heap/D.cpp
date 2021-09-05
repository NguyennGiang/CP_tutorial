#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define fi first
#define se second
#define pii pair<int , int>
#define piii pair<pii, int>

using namespace std;

int main(){
	fast_io
	int n; 
	cin >> n;
	priority_queue<piii, vector<piii>, greater<piii> > minHeap;
	for (int i = 0; i < n; i++){
		int c, t; 
		cin >> t >> c; 
		minHeap.push(make_pair(make_pair(t, t - c), i));
	} 
	int d = 0;
	cout << endl;
	priority_queue <pii, vector <pii>, greater<pii> > result;
	while(!minHeap.empty()){
		piii x = minHeap.top();
		minHeap.pop();
		cout << d << " " << x.fi.fi << " " << x.se << endl;
		d = max(d + 1, x.fi.fi);
		
		minHeap.push(make_pair(make_pair(d, x.fi.se), x.se));
		x = minHeap.top();
		cout << x.fi.fi << " " << x.fi.se << " " << x.se << endl;
		minHeap.pop();
		result.push(make_pair(x.se, d));
		cout << "____________\n";
	}
	// while(!result.empty()){
	// 	cout << result.top().se << " ";
	// 	result.pop();
	// }

	return 0;
}