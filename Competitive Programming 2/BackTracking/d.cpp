#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = 100;
int a[N][M];
int n, m;

int numLight;
bool row[N], col[M];
int step;


void solve(int i, int n, bool fake_row[]){
	if (i == n) {

		bool fake_col[m];
		memset(fake_col, false, sizeof(fake_col));

		int fake_step = 0;
		int cnt = 0;

   		for (int k = 0; k < n; k++){
   			if(fake_row[k] == true){
   				fake_step++;
   			}
   		}

   		for (int j = 0; j < m; j++){
   			int dem = 0; 
   			for (int k = 0; k < n; k++){
   				if (fake_row[k] == true && a[k][j] == 0){
   					dem++;
   				}
   				else if (fake_row[k] == false && a[k][j] == 1){
   					dem++;
   				}
   			}

   			if (dem < n - dem){ 
   				cnt += n - dem;
   				fake_step++;
   				fake_col[j] = true;
   			}
   			else {
   				cnt += dem;
   			}
   		}

   		if (cnt > numLight){

   			numLight = cnt;
   			step = fake_step;

   			for (int i = 0; i < n; i++){
				  row[i] = (fake_row[i] == true);
		  	}

		  	for (int j = 0; j < m; j++){
			  	col[j] = (fake_col[j] == true); 
		  	}
   		}		

    	return;
 	}
    fake_row[i] = 1;
    solve(i + 1, n, fake_row);
    fake_row[i] = 0;
    solve(i + 1, n, fake_row);

}
int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
    
	numLight = 0;
	bool fake_row[n];
	memset(fake_row, false, sizeof(fake_row));
	

	solve(0, n, fake_row); // i_id, step, fake_col, fake_row;
	cout <<  numLight << '\n' << step << '\n';
    for (int i = 0 ; i < n; i++){
        if (row[i] == true){
        cout << "R" << i + 1 << '\n';
        }
    }
    for (int j = 0; j < m; j++){
        if (col[j] == true){
        cout << "C" << j + 1 << '\n';
        }
    }
	return 0;
}