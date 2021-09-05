#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    vector <int> A(n);
	    for(int i = 0; i < n; i++) cin >> A[i];
	    int start = 0;
	    int end = n - 1;
	    while(s[start] == '0'){
	        start++;
	    }
	    while(s[end] == '0'){
	        end--;
	    }
	    long long int ans = 0;
	    ans = (A[start] - A[0]) + (A[n-1] - A[end]);
	    for(int i = start; i < end; i++){
	        int k;
	        for(k = i + 1; k <= end; k++){
	            if(s[k] == '1') break;
	        }

	        int find = INT_MIN;
	        for(int j = i + 1; j <= k; j++){
	            find = max(find, A[j] - A[j-1]);
	        }
	        ans = ans + (A[k] - A[i]) - (find);
	        i = k - 1;
	    }
	    cout << ans << endl;
	}
	return 0;
}
