/*
	--> CITY (PTNK 2012-2013)
*/

#include <iostream>

using namespace std;

const int maxn = 505;
int n, m, k;
int a[maxn][maxn] = {0};
int b[maxn][maxn];
pair <int, int> nei[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

void sum(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int total = 0;
			for (int k = 0; k < 8; k++){
				total += a[i + nei[k].first][j + nei[k].second]; 
			}
			b[i][j] = total;
		}
	}
}

int Liner(int num){
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if(b[i][j] == num){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	sum();
	//cout << Liner(19);

	while(k--){
		int num;
		cin >> num;
		cout << Liner(num) << " ";
	}
	return 0;
}