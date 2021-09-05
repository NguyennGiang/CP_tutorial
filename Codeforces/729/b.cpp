#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ll long long

using namespace std;
int read() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int main(){
	int t = read();
	while(t--){	
		int n, a, b;
		n = read(); a = read(); b = read();

		int oce = 0;
		for (ll x = 1; x <= n; x *= a){
			if ((n - x) % b == 0){
				oce = 1;
				break;
			}
			if (a == 1){
				break;
			}

		}
		if (oce){
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}