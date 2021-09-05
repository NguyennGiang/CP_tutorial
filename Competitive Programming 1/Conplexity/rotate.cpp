/*
	--> Rorate (Round 1A 2010 - Code jam 2010)
*/

#include <iostream>
#define fi first
#define se second

using namespace std;

typedef pair <int ,int> pii;

int n, k;
char m[1000][1000];

void gravity(){
	for (int i = 0; i < n; i++){
		int k = n - 1;
		for (int j = n - 1; j >= 0; j--){
			if (m[i][j] == '.') continue;
			while(k > j && m[i][k] != '.'){
				k--;
			}
			swap(m[i][j], m[i][k]);
		}
		
	}
}

pair <int, int> check_row(int r){
	int x = 0, y = 0;
	int a = 0, b = 0;

	for (int i = 0; i < n; i++){
		if (m[r][i] == 'R') a++;
		else a = 0;
		if (m[r][i] == 'B') b++;
		else b = 0;

		x = max(x, a);
		y = max(y, b);
	}
	return {x, y};
}

pair <int, int> check_col(int c){
	int x = 0, y = 0;
	int a = 0, b = 0;

	for (int i = 0; i < n; i++){
		if (m[i][c] == 'R') a++;
		else a = 0;
		if (m[i][c] == 'B') b++;
		else b = 0;

		x = max(x, a);
		y = max(y, b);
	}
	return {x, y};
}

pair <int ,int> cheo1(int i, int j){
	int x = 0, y = 0;
	int a = 0, b = 0;
	for (int k = 0; k < n; k++) {
		if (i + k >= n || j + k >= n){
			break;
		}

		if (m[i+k][j+k] == 'R') a++;
		else a = 0;
		if (m[i+k][j+k] == 'B') b++;
		else b = 0;

		x = max(x, a);
		y = max(y, b);
	}
	return {x, y};
}

pair <int ,int> cheo2(int i, int j){
	int x = 0, y = 0;
	int a = 0, b = 0;
	for (int k = 0; k < n; k++) {
		if (i + k >= n || j - k < 0){
			break;
		}

		if (m[i+k][j-k] == 'R') a++;
		else a = 0;
		if (m[i+k][j-k] == 'B') b++;
		else b = 0;

		x = max(x, a);
		y = max(y, b);
	}
	return {x, y};
}

int main(){
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cin >> n >> k;
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> m[i][j];
			}
		}

		gravity();

		bool b = false, r = false;

		for (int i = 0; i < n; i++){
			pii tmp = check_row(i);
			if (tmp.fi >= k){
				r = true;
			}
			if (tmp.se >= k){
				b = true;
			}
		}

		for (int j = 0; j < n; j++){
			pii tmp = check_col(j);
			if (tmp.fi >= k) r = true;
			if (tmp.se >= k) b = true;
		}

		for (int i = 0; i < n; i++){
			
			pii tmp = cheo1(i, 0);
			if (tmp.fi >= k) r = true;
			if (tmp.se >= k) b = true;

			tmp = cheo1(0, i);

			if (tmp.fi >= k) r = true;
			if (tmp.se >= k) b = true;
		}

		for (int i = 0; i < n; i++){
			pii tmp = cheo2(0, i);
			if(tmp.fi >= k) r = true;
			if (tmp.se >= k) b = true;

			tmp = cheo2(i, n - 1);
			if (tmp.fi >= k) r = true;
			if (tmp.se >= k) b = true;
		}

		cout << "Case  #" << tc << ": "; 
		//cout << r << " " << b << endl;
		if(r && b){
			cout << "Both\n";
			continue;
		}

		if (!r && !b){
			cout << "Neither\n";
			continue;
		}

		if (r && !b){
			cout << "Red\n";
		}

		if(!r && b){
			cout << "Blue\n";
		}
	}
	return 0;
}