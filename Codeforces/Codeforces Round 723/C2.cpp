#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
	fast_io
	int n; 
	cin >> n;
	int a[n];
	priority_queue <int> maxHeap;
	for (int i = 0; i < n; i++) cin >> a[i];
	int result = 0; 
	int healthy = 0;
	for (int i = 0; i < n; i++){
		if(a >= 0){
			healthy += a[i];
			result++;
		}
		else {
			maxHeap.push(a[i]);
		}
	}
	while(!maxHeap.empty() && healthy + maxHeap.top() >= 0){
		healthy += maxHeap.top();
		maxHeap.pop();
		result++;
	}
	cout << result << " " << healthy;
}