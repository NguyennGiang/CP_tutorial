#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int N = 1e5 + 5;
int n, q;
int f[4 * N], sz[4 * N], a[N];

#define idL (id << 1)
#define idR (idL | 1)
struct node {
	int l, r, id;
	node (int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
	node left(){
		return node(l, l + r >> 1, idL);
	}
	node right(){
		return node((l + r >> 1) + 1, r, idR);
	}

	void build(){
		if(l > r) return ;
		if (l == r){
			sz[id] = 1;
			f[id] = a[l];
			return;
		}

		left().build();
		right().build();
		sz[id] = r - l + 1;
		f[id] = max(f[idL], f[idR]);
	}

	int erase(int i){
		if (l == r){
			f[id] = -1, sz[id] = 0;
			return l;
		}
		int pos;
		if (sz[idL] >= i){
			pos = left().erase(i);
		}
		else {
			pos = right().erase(i - sz[idL]);
		}
		sz[id]--;
		f[id] = max(f[idL], f[idR]);
		return pos;
	}

	int getMax(int i, int j){
		if (l > r || r < i || j < l) return -1;
		if (i <= l && r <= j) return f[id];
		return max(left().getMax(i, j), right().getMax(i, j));
	}
};

struct fenwickTree  {
	int bit[N];
	void update(int i){
		for (; i < N; i += i & -i) bit[i]++;
	}

	int get(int i){
		int s = 0;
		for (; i; i -= i & -i) s += bit[i];
		return s;
	}
}BIT;

int bsL(int x){
	int l = 1, r = n, k = -1;

	while(l <= r){
		int m = l + r >> 1;
		if (BIT.get(m) >= x){
			k = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return k;
}

int bsR(int x){
	int l = 1, r = n, k = -1;
	while(l <= r){
		int m = l + r >> 1;
		if (BIT.get(m) <= x){
			k = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return k;
}

void solve(){
	cin >> n;
	node root(1, n, 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	root.build();
	int ans, pos, x, y;
	char ch;
	cin >> q;
	while(q--){
		cin >> ch;
		if(ch == 'D'){
			cin >> pos;
			pos = root.erase(pos);
			BIT.update(pos);
		}
		else {
			cin >> x >> y;
			if (x < 0) x = 0;
			if (y > n) y = n;
			x = bsL(x), y = bsR(y);
			if (x < 0 || y < 0) ans = -1;
			else {
				ans = root.getMax(x, y);
			}
			cout << ans << endl;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

