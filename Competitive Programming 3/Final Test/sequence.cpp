#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000
typedef pair<int, int> pii;

const int N = 5e5 + 5;
int a[N];
int n;

struct Node{
	int minVal;
	int lazy;
	int minId;
}st[4 * N];

int last[N], prelast[N];

void down(int id){
	int t = st[id].lazy;
	st[2 * id].lazy += t;
	st[2 * id].minVal += t;

	st[2 * id + 1].lazy += t;
	st[2 * id + 1].minVal += t;

	st[id].lazy = 0;
}

void pushup(int id){
	if (st[2 * id].minVal == st[2 * id + 1].minVal){
		st[id].minVal = st[2*id].minVal;
		st[id].minId = st[2 * id].minId;	
	}
	else if (st[2 * id].minVal < st[2 * id + 1].minVal){
		st[id].minVal = st[2 * id].minVal;
		st[id].minId = st[2 * id].minId;
	}
	else {
		st[id].minVal = st[2 * id + 1].minVal;
		st[id].minId = st[2 * id + 1].minId;
	}
}

void build(int id, int l, int r){
	st[id].lazy = 0;
	st[id].minVal = 0;
	if(l == r) {
    st[id].minId = l;
    return ;
  }
    
	int m = (l + r) / 2;
	build(2 * id, l, m);
	build(2 * id + 1, m + 1, r);
	pushup(id);
}

void update(int id, int l, int r, int u, int v, int val){
	if (v < l || r < u){
		return ;
	}

	if (u <= l && r <= v){
		st[id].minVal += val;
		st[id].lazy += val;
		return;
	}
	int mid = (l + r) / 2;
	down(id);

	update(2 * id, l, mid, u, v, val);
	update(2 * id + 1, mid + 1, r, u, v, val);
	pushup(id);
}

pair<int, int> getMin(int id, int l, int r, int u,  int v){
	if (v < l || r < u) return {N, -1};

	if (u <= l && r <= v){
		return {st[id].minVal, st[id].minId};
	}
	int mid = (l + r) / 2;
	down(id);

	pii left = getMin(2 * id, l, mid, u, v);
	pii right = getMin(2 * id + 1, mid + 1, r, u, v);

	if (left.fi <= right.fi){
		return {left.fi, left.se};
	}
	else {
		return {right.fi, right.se};
	}
}

void solve(){
  
	build(1, 1 , n);
  pii ans = {N, -1};
 
	for (int r = 1; r <= n; r++){
		if (last[a[r]] != 0){
			update(1, 1, n, prelast[a[r]] + 1, last[a[r]], -1);
		}
		update(1, 1, n, last[a[r]] + 1, r, 1);
		
		pii tmp = getMin(1, 1, n, 1, r);
		int x = tmp.fi, y = r - tmp.se + 1;
		if (x < ans.fi){
			ans.fi = x;
			ans.se = y;
		}
		else if (x == ans.fi && y > ans.se){
			ans.se = y;
		}

		prelast[a[r]] = last[a[r]];
		last[a[r]] = r;
	}

	cout << ans.fi << " " << ans.se << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){

		for(int i = 1; i <= n; i++){
			cin >> a[i];
      last[a[i]] = 0;
      prelast[a[i]] = 0;
		}
		solve();
	}

	return 0;
}
