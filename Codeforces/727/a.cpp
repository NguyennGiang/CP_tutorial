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
	int k = read();

	while(k--){
		ll n, x, t;
		cin >> n >> x >> t;
	
		ll a = t / x;
		if (x > t){
			cout << 0 << '\n';
		}
		else if(x == t){
			cout << n - 1 << '\n';
		}
		else if (a >= n){
			cout << n * (n - 1) / 2 << '\n';
		}
		else {
			cout << (n - a) * a + a * (a - 1) / 2 << '\n';
		}
	}
	return 0;
}