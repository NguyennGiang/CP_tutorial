#include<bits/stdc++.h>
using namespace std;

int n;
int m;
 
long long calc (long long x) {
	if (x < 1) return 0;
	if (x % 4 == 0) return x;
	if (x % 4 == 1) return 1;
	if (x % 4 == 2) return x + 1;
	return 0;
}
 
int main() {
	int n;
	scanf ("%d", &n);
	long long cur = 0; 
	for (int i = 0; i < n; i++) {
		long long x, m;  
		cin >> x >> m;
		cur ^= calc (x - 1);
		cur ^= calc (x + m - 1);
	}
	if (cur) printf ("tolik\n"); else printf ("bolik\n");
	return 0;
}