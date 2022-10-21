#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long quickpow(int a,int b){
	if (b == 0) return 1;
	long long x = quickpow(a, b >> 1);
	x = x * x % mod;
	if (b & 1){
		x = x * a % mod;
	}
	return x;
}

int main(){
	long long f[5005];
	f[0] = 1;
	for (int i = 0; i <= 5000; i++){
		f[i+1] = (f[i] * (4 * i + 2) % mod) * quickpow(i + 2, mod - 2) % mod;
	}

	int n;
	cin >> n;
	while(n--){
		int x; cin >> x;
		cout << f[x] << endl;
	}
	return 0;
}
