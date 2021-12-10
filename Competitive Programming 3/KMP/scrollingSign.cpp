#include <bits/stdc++.h>
using namespace std;

const int N = 105;
string str, total;
int a, b;

bool isMatch(int pos){
	for (int i = pos; i < total.size(); i++){
		if (total[i] != str[i - pos]) return false;
	}
	return true;
}

void minimize(){
	int pos = total.size() - a;
	for (int i = pos; i < total.size(); i ++){
		if (isMatch(i)){
			for (int j = total.size() - i; j < str.size(); j++){
				total += str[j];
			}
			return;
		}
	}
	total += str;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		total = "";
		for (int x = 0; x < b; x++){
			cin >> str;
			minimize();
		}
		cout << total.size() << endl;
	}
	return 0;
}
