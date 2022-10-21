#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

struct Point {
    int x, y;
};

struct Line {
    Point s, e;
};

void solve(Line a, Line b){
    int a1, b1, c1, a2, b2, c2;
    long long d, dx, dy;
      
    a1 = a.s.y - a.e.y, b1 = -a.s.x + a.e.x;
    a2 = b.s.y - b.e.y, b2 = -b.s.x + b.e.x;
    c1 = a1 * a.s.x + b1 * a.s.y;
    c2 = a2 * b.s.x + b2 * b.s.y;
      
    d = 1LL * a1 * b2 - 1LL * a2 * b1;
    dx = 1LL * c1 * b2 - 1LL * c2 * b1;
    dy = 1LL * a1 * c2 - 1LL * a2 * c1;
      
      //cout << d << ' ' << dx << ' ' << dy << '\n';
    if (!d && (dx || dy)){
        cout << "NONE\n";
    }
    else if (!d && !dx && !dy) {
        cout << "LINE\n";
    }
    else {
        cout << fixed << setprecision(2) << "POINT " << 1.0 * dx / d << " " << 1.0 * dy/d << '\n';
    }
}

void solve(){
    Line a, b;
    cin >> a.s.x >> a.s.y >> a.e.x >> a.e.y;
    cin >> b.s.x >> b.s.y >> b.e.x >> b.e.y;
    solve(a, b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINEJUDGE
        clock_t tStart = clock();
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif

    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT\n";
    while(t--){
        solve();
    }
    cout << "END OF OUTPUT";
    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}