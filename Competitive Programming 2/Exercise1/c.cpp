#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define N  26
int main(){
	string s;
	map <string, int> map;
	string alpha[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v","w", "x", "y", "z" };
	int id = 1;

	for (int i = 0 ; i < N; i++){
		map["" + alpha[i]] = id++;
	}

	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			map["" + alpha[i] + alpha[j]] = id++;
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int m = j + 1; m < N; m++){
				map["" + alpha[i] + alpha[j] + alpha[m]] = id++;
			}
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int m = j + 1; m < N; m++){
				for (int n = m + 1; n < N; n++){
					map["" + alpha[i] + alpha[j] + alpha[m] + alpha[n]] = id++;
				}			
			}
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int m = j + 1; m < N; m++){
				for (int n = m + 1; n < N; n++){
					for (int k = n + 1; k < N; k++){
						map["" + alpha[i] + alpha[j] + alpha[m] + alpha[n] + alpha[k]] = id++;
					}				
				}			
			}
		}
	}
	while(cin >> s){
		cout << map[s] << endl;
	}
	return 0;
}