#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define oo 1000000000

const int MAX_DIGIT = 256;

void countingSort(vector<int>& SA, vector<int>& RA, int k = 0){
    int n = SA.size();
    vector<int> cnt(max(n, MAX_DIGIT));

    for (int i = 0; i < n; i++){
        if (i + k < n){
            cnt[RA[i + k]]++;
        }
        else cnt[0]++;
    }

    for (int i = 1; i < cnt.size(); i++){
        cnt[i] += cnt[i-1];
    }

    vector<int> tempSA(n);

    for (int i = n - 1; i >= 0; i--){
        if (SA[i] + k < n){
            tempSA[--cnt[RA[SA[i] + k]]] = SA[i];
        }
        else tempSA[--cnt[0]] = SA[i];
    }
    SA = tempSA;
}

vector<int> build(const string& s){
    int n = s.length();
    vector <int> SA(n), RA(n), tempRA(n);

    for (int i = 0; i < n; i++){
        RA[i] = s[i];
        SA[i] = i;
    }
    for (int step = 1; step < n; step <<= 1){
        countingSort(SA, RA, step);
        countingSort(SA, RA, 0);

        tempRA[SA[0]] = 0;

        for (int i = 1; i < n; i++){
            if (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + step] == RA[SA[i-1] + step]){
                tempRA[SA[i]] = tempRA[SA[i-1]];
            }
            else {
                tempRA[SA[i]] = tempRA[SA[i-1]] + 1;
            }
        }
        RA = tempRA;
        if (RA[SA[n - 1]] == n - 1) break;
    }
    return SA;
}


vector<int> buildLCP(const string& s, const vector<int>& SA){
    int n = SA.size();
    vector<int> LCP(n); // longest common prefix
    vector<int> PLCP(n);
    vector<int> c(n, 0);

    for (int i = 0; i < n; i++){
        c[SA[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n - 1; i++){
        int j = SA[c[i] - 1];
        k = max(k - 1, 0);
        while(s[i + k] == s[j + k]) k++;
        PLCP[i] = k;
    }

    for (int i = 0; i < n; i++){
        LCP[i] = PLCP[SA[i]];
    }
    return LCP;
}

void solve(){
	string a, b;
	cin >> a >> b;
	string s = a + '#' + b + '$';
	vector<int> SA = build(s);
	vector<int> LCP = buildLCP(s, SA);
	int ans = 0;
	for (int i = 1; i < s.size(); i++){
		if (SA[i-1] < a.size() && SA[i] > a.size() || SA[i] < a.size() && SA[i-1] > a.size()){
			ans = max(ans, LCP[i]);
		}
	}
	cout << ans << endl;

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

