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
	int n = read(), q = read();

	string s;
	cin >> s;
	int a[n + 1] = {0};
	int id[27] ={0};
	for (int i = 0; i <= 26; i++){
		id[i] = i;
	}

	for (int i = 1; i <= s.length(); i++){
		a[i] = a[i - 1] + id[s[i - 1] - 96];
	}
	//for(auto ai : a) cout << ai << " ";
	while(q--){
		int l = read(), r = read();
		cout << a[r] - a[l-1] << '\n';
	}
	return 0;
}