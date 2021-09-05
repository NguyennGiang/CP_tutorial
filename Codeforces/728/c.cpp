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
		int n = read();
		vector <int> a(n);
		for (auto & ai : a) ai = read();

		sort(a.begin(), a.end());
		vector <ll> dir(n);
		for (int i = 0; i < n - 1; i ++){
			dir[i] = a[i + 1] - a[i];
		}

		ll res = 0;
		for (int i = 0; i < n - 1; i++){
			res += dir[i];
		}
		for (int i = 0; i < n - 1; i++){
			res -= dir[i] * (i + 1) * (n - i - 1);
		}
		cout << res << '\n';
	}
	return 0;
}