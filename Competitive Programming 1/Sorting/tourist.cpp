/*
	--> Tourist (Facebook Hacker Cup 2018 Qualificatio Round)
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Place
{
	int x;
	string s;
};

bool compare (Place a, Place b){
	return a.x < b.x;
}


void solve(int tc){
	long long n, k, v;
	cin >> n >> k >> v; 
	string s[n];
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}

	long long cur = k * (v - 1) % n;

	Place tourist[k];

	for (int i = 0; i < k; i++){
		tourist[i].x = (cur + i) % n;
		tourist[i].s = s[(cur + i) % n];
	}

	sort(tourist, tourist + k, compare);

	cout << "Case #" << tc << ": ";

	for (int i = 0; i < k; i++) {
		cout << tourist[i].s << " ";
	}
	cout << '\n';
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		solve(i + 1);
	}
	return 0;
}