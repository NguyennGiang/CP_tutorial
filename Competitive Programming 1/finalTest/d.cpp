#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void on_gird(vector <vector<int>> &gird,const int x,const int y){
	if (gird[x][y] == 0){
		gird[x][y] = 2;
	}
	else return;

	if (x > 0){
		on_gird(gird, x - 1, y);
	}

	if (x < gird.size() - 1){
		on_gird(gird, x + 1, y);
	}
	if (y > 0){
		on_gird(gird, x, y - 1);
	}
	if (y < gird[0].size() - 1){
		on_gird(gird, x, y + 1);
	}
	return ;
}

int make_coast(vector<vector <int>> &gird){
	int coast = 0;
	for (int i = 0; i < gird.size(); i++){
		for (int j = 0; j < gird[0].size(); j++){

			if (gird[i][j] == 1){

				if (j > 0){
					if (gird[i][j-1] == 2){
						coast++;
					}
				}
				else coast++;

				if (j < gird[0].size() - 1){
					if (gird[i][j+1] == 2){
						coast++;
					}
				}
				else coast++;

				if (i < gird.size() - 1){
					if (gird[i+1][j] == 2){
						coast++;
					}
				}
				else coast++;

				if (i > 0){
					if (gird[i-1][j] == 2){
						coast++;
					}
				}
				else coast++;
			}

		}
	}
	return coast;
}

int main(){
	
	RASENGAN

	int r, c;
	cin >> r >> c;
	vector<vector <int>> gird (r, vector<int> (c, 0));

	string s;

	for(auto & r : gird){
		cin >> s;
		for (int j = 0; j < c; j++){
			r[j] = s[j] - '0';
		}
	}


	for (int i = 0; i < r; i++){
		on_gird(gird, i, 0);
	}

	for (int i = 0; i < r; i++){
		on_gird(gird, i , c - 1);
	}

	for (int i = 0; i < c; i++){
		on_gird(gird, 0, i);
	}
	for (int i = 0; i < c; i++){
		on_gird(gird, r - 1, i);
	}

	cout << make_coast(gird) << '\n';

	return 0;
}