#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
long long dp[N];
int coins[5] = {1, 5, 10, 25, 50};

void init(){
	dp[0] = 1;
	for (int i = 1; i <= 5; i++){
		for (int j = coins[i-1]; j < N; j++){
			dp[j] = dp[j] + dp[j - coins[i-1]];
		}
	}
}

int main(){
	init();
	int n;
	while(cin >> n){
		cout << dp[n] << '\n';
	}
	return 0;
}
