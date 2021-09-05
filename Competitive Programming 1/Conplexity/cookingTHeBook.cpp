/*
	--> Cooking the Books (Facebook hackercup 2015 - Qualification Round)
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int toNum(int digit[], int n){
	int res = 0;

	for (int i = n - 1; i >= 0; i--){
		res = res * 10 + digit[i];
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	for (int tc = 1; tc <= n; tc++){
		int num;
		cin >> num;
		int digit[10];

		cout << "Case #" << tc << ": ";
		if (num == 0){
			cout << 0 << " " << 0 << '\n';
			continue;
		}

		int numDigit = 0;
		while(num != 0){
			digit[numDigit] = num % 10;
			num = num / 10;
			numDigit++;
		}

		int arr[1000];

		arr[0] = toNum(digit, numDigit);
		int id = 1;

		for (int i = 0; i < numDigit; i++){
			for (int j = i + 1; j < numDigit; j++){
				swap(digit[i], digit[j]);
				int ans = toNum(digit, numDigit);

				if (ans > pow(10, numDigit - 1)){
					arr[id] = ans;
					id++;
				}
				swap(digit[i], digit[j]);
			}
		}

		sort(arr, arr + id);
		cout << arr[0] << " " << arr[id-1] << '\n';
	}
	return 0;
}