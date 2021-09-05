#include <bits/stdc++.h>
#define ll long long 
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void solve(){
	ll n; 
	cin >> n;
	ll healthy = 0;
	priority_queue <ll, vector<ll>, greater <ll> > minHeap;
	for (int i = 0; i < n; i++){
		ll num; 
		cin >> num;
		healthy += num; 
		minHeap.push(num);
		while(healthy < 0){
			healthy -= minHeap.top();
			minHeap.pop();
		}
	}
	
	cout << minHeap.size();
}

int main(){
	solve();
	return 0;
}