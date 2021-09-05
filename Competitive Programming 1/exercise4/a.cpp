#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct info
{
	int p, m, t;
};

int N, M, D, S;
info data[1001];
int milk[55], candidate[55];

int main(){
	RASENGAN

	cin >> N >> M >> D >> S;
	for (int i = 0; i < D; i++){
		cin >> data[i].p >> data[i].m >> data[i].t;
	}
	for (int i = 0; i < S; i++){
		int per, time;
		cin >> per >> time;

		for (int j = 0; j < D; j++){
			if (data[j].p == per && data[j].t <= time){
				milk[data[j].m]++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 50; i++){
		if (milk[i] >= S){
			memset(candidate, 0, sizeof(candidate));
			int cnt = 0;
			for (int j = 0; j < D; j++){
				if (data[j].m == i && candidate[data[j].p] == 0){
					candidate[data[j].p] = 1;
					cnt++;
				}
			}
			ans = max (ans, cnt);
		}
	}
	cout << ans << '\n';
	return 0;
}