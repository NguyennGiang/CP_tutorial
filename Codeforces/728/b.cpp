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
		vector <pair <int, int>> pairs;
		for (auto & ai : a) ai = read();
		for (int i = 0; i < n; i++){
			pairs.push_back({a[i], i + 1});
		}

		sort(pairs.begin(), pairs.end());

		ll cnt = 0;
		
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				ll L = 1ll *pairs[i].f * pairs[j].f;
				ll R = pairs[i].s + pairs[j].s;
				if (L > 2 * n) break;
				if (L == R) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}