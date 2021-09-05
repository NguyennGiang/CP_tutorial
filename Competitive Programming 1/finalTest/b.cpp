#include <iostream>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
	RASENGAN

	int n, m;
	cin >> n >> m;
	int road[100], cow[100];
	int cur = 0;
	for (int i = 0; i < n; i++){
		int len, speed;
		cin >> len >> speed;
		for (int j = cur; j < cur + len; j++){
			road[j] = speed;
		}
		cur += len;
	}
	cur = 0;
	for (int i = 0; i < m; i++){
		int len, speed;
		cin >> len >> speed;
		for (int j = cur; j < cur + len; j++){
			cow[j] = speed;
		} 
		cur += len;
	}

	int res = 0;
	for (int i = 0; i < 100; i++){
		res = max(res, cow[i] - road[i]);
	}
	cout << res;
	return 0;
}	