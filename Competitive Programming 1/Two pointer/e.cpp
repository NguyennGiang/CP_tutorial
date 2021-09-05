#include <bits/stdc++.h>
using namespace std;
const int  maxn = 1e5;
#define ll long long

int t,n,a[maxn],cnt[4];

void solve(){
	ll ans = 0,sum;
	for (int i = 0; i < n; i++) {
		
		sum = 0;
		memset(cnt,0,sizeof(cnt));
		for (int j = i + 1; j < n; j++) cnt[a[j]]++; 
        //for (int i = 0; i < 4; i++) cout << cnt[i] << " ";
        //cout << endl;
		for(int j = i - 1; j >= 0; j--){
            // cout << a[j] << " ";
			if(a[j]==a[i]){
				
				ans+=sum;
			}
			sum += cnt[a[j]];
		}
        // cout << endl << sum << endl;
	}
	cout << ans << endl;
}
int main(){
	cin >> t; 
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		solve();
	}
	return 0;
}
