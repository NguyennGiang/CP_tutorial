#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector <int> pref;

void preprocess(){
	int j = 0;
	for (int i = 1; i < n; i++){
		while(j > 0 && s[i] != s[j]){
			j = pref[j-1];
		}
		if (s[i] == s[j]){
			j++;
		}
		pref[i] = j;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1){
		cin >> s;
		if (s == "."){
			break;
		}
		n = s.length();
		pref.resize(n);
		preprocess();
		int k = n - pref[n-1];
		int res = (n % k == 0? n/k : 1);
		cout << res << endl;
	}
	return 0;
}
