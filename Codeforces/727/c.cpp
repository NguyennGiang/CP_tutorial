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
	int n;
	ll k, x;
	cin >> n >> k >> x;
	vector <ll> a(n);
	for (auto &ai : a) cin >> ai;
	sort(a.begin(), a.end());
	vector <ll> b;
	int res = n;
	for (int i = 1; i < n; i++){
		ll d = a[i] - a[i -1];
		if (d <= x){
			res--;
		}
		else{
			b.push_back((d - 1) / x);
		}	
	}
	sort(b.begin(), b.end());
	for (ll v : b){
		if (k >= v){
			res--;
			k -= v;
		}
	}

	cout << res << '\n';
}