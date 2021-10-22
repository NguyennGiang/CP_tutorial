#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
typedef pair <int, int> pii;

const int N = 20005;
pii doll[N];
vector <pii> v;
int n;

bool cmp(const pii &l, const pii &r){
    if (l.f == r.f) return l.s > r.s;
    return l.f < r.f;
}

void solve(){
    sort(doll, doll + n, cmp);
    v.clear();
    v.push_back(doll[n-1]);
    for (int i = n - 2; i >= 0; i--){
        int hi = v.size() - 1, lo = 0;
        while (lo <= hi){
            int m = (lo + hi) / 2;
            if (v[m].f == doll[i].f || v[m].s <= doll[i].s){
                lo = m + 1;
            }
            else hi = m - 1;
        }
        if (lo == v.size()){
            v.push_back(doll[i]);
        }
        else v[lo] = doll[i];

    }
    // for (int i = 0; i < v.size(); i++){
    //     printf("%d %d\n", v[i].f, v[i].s);
    // }
    printf("%d\n", v.size());
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d%d", &doll[i].f, &doll[i].s);
        }
        solve();
    }
    return 0;
}