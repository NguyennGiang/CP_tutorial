#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

struct Point {
    double x, y;
};
const double PI = acos(-1.0);
Point po[100005];
int n;
Point T;

double dis(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dot(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}

double length(Point a){
    return sqrt(dot(a, a));
}

double point_to_seg(Point a, Point b, Point c){
    Point v1, v2, v3;

    v1.x = c.x - b.x;
    v1.y = c.y - b.y;

    v2.x = a.x - b.x;
    v2.y = a.y - b.y;

    v3.x = a.x - c.x;
    v3.y = a.y - c.y;

    if (dot(v1, v2) < 0) return length(v2);
    else if(dot(v1, v3) > 0) return length(v3);
    else {
        return fabs((v1.x * v2.y - v2.x * v1.y) / length(v1));
    }
}

void solve(){
    cin >> n;
    cin >> T.x >> T.y;
    for (int i = 0; i < n; i++){
        cin >> po[i].x >> po[i].y;
    }

    po[n] = po[0];

    double r = 0;
    double l = 1000000000.0;

    for (int i = 0; i < n; i++){
        r = max(r, dis(T, po[i]));
        l = min(l, point_to_seg(T, po[i], po[i+1]));
    }

    cout << fixed << setprecision(20) << (r * r - l * l) * PI ;
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
    //cin >> t;
    while(t--){
        solve();
    }

    #ifdef ONLINEJUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); 
    #endif
    return 0;
}