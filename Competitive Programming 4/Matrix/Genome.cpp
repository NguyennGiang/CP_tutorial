#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

ll n, m, k;
ll mm[60][60];
map<char, int> st;

struct mat {
    ll a[60][60];
    mat(){
        memset(a, 0, sizeof(a));
    }
    mat operator * (mat & b){
        mat ans;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                for (int k = 0; k < m; k++){
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        return ans;
    }
};

mat pow(mat a, ll b){
    mat ans;
    for (int i = 0; i <= 52; i++){
        ans.a[i][i] = 1;
    }

    while(b){
        if (b & 1) ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}

void init(){
    for (int i = 0; i <= 52; i++){
        for (int j = i; j <= 52; j++){
            mm[i][j] = mm[j][i] = 1;
        }
    }
    int k = 'a';
    for (int i = 0; i < 26; i++){
        st[k++] = i;
    }
    k = 'A';
    for (int i = 26; i < 52; i++){
        st[k++] = i;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

    // Code below

    cin >> n >> m >> k;
    init();
    string s;
    int x, y;
    for (int i = 1; i <= k; i++){
        cin >> s;
        x = st[s[0]];
        y = st[s[1]];
        mm[x][y] = 0;
    }
    mat ans;
    for (int i = 0; i < m; i++){
        memcpy(ans.a[i], mm[i], sizeof(mm[i]));
    }

    ans = pow(ans, n - 1);
    ll sum  = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            sum = (sum + ans.a[i][j]) % MOD;
        }
    }
    cout << sum << endl;
    return 0;
}