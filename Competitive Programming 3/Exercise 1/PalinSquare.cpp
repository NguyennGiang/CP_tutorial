#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll base = 43;
const ll mod = 1e9 + 7;
const int N = 200 + 5;

string s[N];
ll n;

class StringHash {
public:
    ll mod, f_hash[N] = {}, r_hash[N] = {}, base_pow[N];
    StringHash() {}

    StringHash(const string &s, ll mod){
        this->mod = mod;
        base_pow[0] = 1;
        for (int i = 0, j = n - 1; i < n; i++, j--){
            f_hash[i+1] = (f_hash[i] * base + s[i]) % mod;
            base_pow[i+1] = (base_pow[i] * base) % mod;
            r_hash[j+1] = (r_hash[j+2] * base + s[j]) % mod;
        }
    }

    ll forward_hash(int i, int j){
        ll hash = f_hash[j + 1] - (f_hash[i] * base_pow[j-i+1]) % mod;
        return hash < 0 ? hash + mod : hash;
    }

    ll reverse_hash(int i, int j){
        ll hash = r_hash[i+1] - (r_hash[j+2] * base_pow[j-i+1]) % mod;
        return hash < 0 ? hash + mod : hash;
    }
};

StringHash row[N], col[N];

bool check(int len){
    for (int i = 0; i < n - len + 1; i++){
        for (int j = 0; j < n - len + 1; j++){
            bool row_found = true, col_found = true;

            for (int k = i; k < i + len; k++){
                if (row[k].forward_hash(j, j + len - 1) != row[k].reverse_hash(j, j + len - 1)){
                    row_found = false;
                    break;
                }
            }

            for (int k = j; k < j + len; k++){
                if (col[k].forward_hash(i, i + len - 1) != col[k].reverse_hash(i, i + len - 1)){
                    col_found = false;
                    break;
                }
            }

            if (row_found && col_found){
                return true;
            }
        }
    }
    return false;
}

int BS(){
    int low = 0, high = n, mid, res = 1;
    while (low <= high){
        mid = (low + high) >> 1;
        bool done = false;
        if (check(mid)){
            done = true;
            res = max(res, mid);
            low = mid + 1;
        }
        if (mid + 1 <= n && check(mid + 1)){
            done = true;
            res = max(res, mid + 1);
            low = mid + 2;
        }
        if (!done) {
            high = mid - 1;
        }
    }
    return res;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    for (int i = 0; i < n; i++){
        row[i] = StringHash(s[i], mod);
        string col_str;
        for (int j = 0; j < n; j++){
            col_str += s[j][i];
        }
        col[i] = StringHash(col_str, mod);
    }

    cout << BS();
    return 0;
}

// Time O(n ^ 3logn);