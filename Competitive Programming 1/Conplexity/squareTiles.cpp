/*
	--> Square tiles (Round 1C 2011 - Code jam 2011)
*/

#include <iostream>

using namespace std;

void solve(char m[53][53], int r, int c){
	for (int i = 0; i < r - 1; i++){
		for (int j = 0; j < c - 1; j++){
			if (m[i][j] == '#' && m[i][j+1] == '#' && m[i+1][j+1] == '#' && m[i+1][j] == '#'){
				m[i][j] = '/';
				m[i+1][j+1] = '/';
				m[i][j+1] = '\\';
				m[i+1][j] = '\\';
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int r, c;
		cin >> r >> c;
		char m[53][53];
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cin >> m[i][j];
			}
		}

		solve(m, r, c);
		int oce = 1;

		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (m[i][j] == '#'){
					oce = 0;
					break;
				}
			}
			if(oce == 0){
				break;
			}
		}

		cout << "Case #" << tc << ":\n";
		if (oce == 1){
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					cout << m[i][j];
				}
				cout << '\n';
			}
		}
		else{
			cout << "Impossible\n";
		}
	} 
	return 0;
}