#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGIT = 256;
const int INF = 1e9;
int lg[100050];

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
        for(int i = 0; i < n; i++){
            RA[i] = tempRA[i];
        }
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

int cnt[11];    

bool check(int k){
    for (int i = 1; i <= k; i++){
        if (!cnt[i]) return 0;
    }
    return 1;
}

int get(int i, int j, const vector<vector<int>>& f){
    int k = lg[j - i + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int solve(const string& a, const int& k){
    string s = a + "$";
    int n = s.size();
    int id = 1;
    
    // mark each string to a integer
    unordered_map<int, int> mp;
    memset(cnt, 0, sizeof(cnt));
    
    for (int i = 0; i < s.size(); i++){
        if (s[i] < 'a') id++;
        else mp[i] = id;
        //cout << mp[i] << ' ';
    }
    
    vector<int> SA = build(s);
    vector<int> LCP = buildLCP(s, SA);
    
    // sparse table
    vector<vector<int>> f(100050, vector<int>(20));
    for (int i = 0; i < n; i++){
        f[i][0] = a[i];
    }
    for (int j = 1; (i << j) <= n; j++){
        int k = 1 << (j - 1);
        for (int i = 0; i + 2 * k <= n; i++){
            f[i][j] = min(f[i][j-1], f[i + step][j-1]);
        }
    }

    // compute answer
    int j = -1;
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        while(!check(k) && j < n){
            j++;
            cnt[mp[SA[j]]]++;
        }
        if (j < n)
          ans = max(ans, get(i + 1, j, f));
        else break;
        cnt[mp[SA[i]]]--;
    }
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lg[1] = 0;
    for (int i = 2; i < 100050; i++){
        lg[i] = lg[i/2] + 1;
    }

    int t; cin >> t;
    string s;
    while(t--){
        int k; cin >> k;
        s = "";
        for (int i = 0; i < k; i++){
            string x; cin >> x;
            if (i > 0) s += char(i + 48);
            s += x;
        }
        if (k == 1) cout << s.size() << endl;
        else cout << solve(s, k) << endl;
    }
    return 0;
}