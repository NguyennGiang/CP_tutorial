#include <iostream>

using namespace std;

void solve(int tc){
	int r, k, n;
	cin >> r >> k >> n;

	long long li[2000];

	for (int i = 0; i < n; i++){
		cin >> li[i];
	}

	long long result_monney[2000] = {0};
	long long result_st[2000] = {0};

	for (int h = 0; h < n; h++){
		long long sum = 0;
		int st = h;
		bool done = false;
		for (int b = 0; b < n; b++){
			if (sum + li[(h + b) % n] <= k){
				sum += li[(h + b) % n];
				st = (st + 1) % n;
			}
			else{
				result_monney[h] = sum;
				result_st[h] = st;
				done = true;
				break;
			}
		}

		if (!done){
			result_monney[h] = sum;
			result_st[h] = st;
		}
	}

	long long money = 0;
	int st = 0;
	for (long long i = 0; i < r; i++){
		money += result_monney[st];
		st = result_st[st];
	}

	cout << "Case #" << tc << ": " << money << endl;
}



int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}