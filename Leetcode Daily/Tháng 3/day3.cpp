#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums){
	int n = nums.size();
	for (int i = 0; i < n - 1; i++) nums[i] -= nums[i+1];

	int curr = 1;
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (nums[i] == nums[i-1]){
			curr++;
		}
		else {
			curr++;
			ans += (curr-1) * (curr - 2) / 2;
			curr = 1;
		}
	}
	return ans;
}

int main(){
	solve();
	return 0;
}
