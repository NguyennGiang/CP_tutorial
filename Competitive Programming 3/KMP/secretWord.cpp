#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
char T[N], P[N];
int f[N], n, m, anslen;

void kmpPreproc(){
	m = strlen(P);
	int i = 0, j = -1;
	f[0] = -1;
	while(i < m){
		while (j >= 0 && P[i] != P[j]){
			j = f[j];
		}
		i++;
		j++;
		f[i] = j;
	}
}

void kmp(){
	n = strlen(T);
	int i = 0, j = 0;
	while (i < n){
		while (j >= 0  && T[i] != P[j]){
			j = f[j];
		}
		i++;
		j++;
		if(j > anslen){
			anslen = j;
		}
		if (j == m){
			j = f[j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--){
		cin >> P;
		int len = strlen(P);
		for (int i = 0; i < len; i++){
			T[i] =P[len - i - 1];
		}
		T[len] = '\0';
		kmpPreproc();
		anslen = -1;
		kmp();
		for (int i = anslen - 1; i >= 0; i--) {
			cout << P[i];
		}
		cout << endl;
	}
	return 0;
}
