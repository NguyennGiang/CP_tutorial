#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

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
//	RASENGAN
	int t = read();
//	cout << t; 
	while(t--){
		int n = read();
		// vector <int> a(n);
		// for (auto &ai : a) ai = read();

		if (n % 2 == 0){
			for (int i = 1; i <= n; i+= 2){
				cout << i + 1 << " " << i << " ";
			}
			cout << '\n';
		}
		else {
			for (int i = 1; i <= n - 3; i+=2){
				cout << i + 1 << " " << i << " ";
			}
			cout << n << " " << n - 2 << " " << n - 1 << '\n';
		}

	}
	return 0;
}