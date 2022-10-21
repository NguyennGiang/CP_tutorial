#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

char s[24], t[24];
int f[24][24], op[24][24];

void output(int i, int j){
    if (!i && !j) return;
    if (op[i][j] == 1){
        output(i-1, j);
        printf("D%c%02d", s[i-1], j + 1);
    }
    else if (op[i][j] == 2){
        output(i, j - 1);
        printf("I%c%02d", t[j-1], j);
    }
    else if (op[i][j] == 3){
        output(i - 1, j - 1);
        printf("C%c%02d", t[j-1], j);
    }
    else output(i - 1, j - 1);
}

void solve(){
    while(scanf("%s", s) && s[0] != '#'){
        scanf("%s", t);
        int l1 = strlen(s);
        int l2 = strlen(t);

        for (int i = 0; i <= l1; i++){
            for (int j = 0; j <= l2; j++){
                f[i][j] = 400;
                op[i][j] = 0;
            }
        }

        for (int i = 0; i <= l1; i++){
            op[i][0] = 1;
            f[i][0] = i;
        }
        for (int i = 0; i <= l2; i++){
            op[0][i] = 2;
            f[0][i] = i;
        }

        for (int i = 1; i <= l1; i++){
            for (int j = 1; j <= l2; j++){
                if (s[i - 1] != t[j - 1]){
                    op[i][j] = 3;
                    f[i][j] = f[i-1][j-1] + 1;
                }
                else {
                    f[i][j] = f[i-1][j-1];
                }

                if (f[i-1][j] + 1 < f[i][j]){
                    op[i][j] = 1;
                    f[i][j] = f[i-1][j] + 1;
                }
                if (f[i][j-1] + 1 < f[i][j]){
                    op[i][j] = 2;
                    f[i][j] = f[i][j-1] + 1;
                }
            }
        }

        output(l1, l2);
        printf("E\n");
    }
    return;
} 

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // #ifdef ONLINEJUDGE
    //     clock_t tStart = clock();
    //     freopen("input.txt","r",stdin); 
    //     freopen("output.txt","w",stdout); 
    // #endif

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}