#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Car
{
	string name;
	int lowest;
	int highest;

	Car(const string &name, const int &lowest, const int &highest)
		:name(name), lowest(lowest), highest(highest) {}

};

vector <Car> a;
int id;

void solve(int i, int cnt, int n, int price){
	if (cnt > 1){
		id = -1;
		return;
	}
	if (i == n){
		return;
	}

	if (a[i].lowest <= price && price <= a[i].highest){
		id = i;
		solve(i + 1, cnt + 1, n, price);
	}
	else {
		solve (i + 1, cnt, n, price);
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			string s;
			int x, y;
			cin >> s >> x >> y;
			a.push_back(Car(s, x, y));
		}

		int q;
		cin >> q;
		while(q--){
			int price;
			cin >> price;
			id = -1;
			solve(0, 0, n, price);
			if (id == -1){
				cout << "UNDETERMINED\n";
			}
			else {
				cout << a[id].name << '\n';
			}
		}
	}
	return 0;
} 