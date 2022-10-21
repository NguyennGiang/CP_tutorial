#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MOD = 1e9 + 7;

struct Line {
    ll a, b;

    Line(ll a = 0, ll b = 0) : a(a), b(b) {}

    double intersecX(const Line& l){
        return 1.0 * (l.b - b) / (a - l.a);
    }

    ll eval(ll x){
        return a * x + b;
    }
};

struct Rect {
    ll x, y, a;
    Rect(ll x = 0, ll y = 0, ll a = 0) : x(x), y(y), a(a) {}

    bool operator <(const Rect &o){
        return x < o.x;
    }
};

int n;
vector<Rect> rects;
deque<Line> cht;

void add(ll a, ll b){
    Line line(a, b);
    while(cht.size() >= 2 && cht[0].intersecX(cht[1]) <= cht[0].intersecX(line)){
        cht.pop_front();
    } 
    cht.push_front(line);
}

long long query(int x){
    int n = cht.size();
    while(n > 1 && cht[n-1].intersecX(cht[n-2]) >= x){
        cht.pop_back();
        n--;
    }
    return cht[n-1].eval(x);
}

void solve(){
    cin >> n;
    ll x, y, a;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> a;
        rects.push_back({x, y, a});
    }
    sort(rects.begin(), rects.end());

    ll res = 0;
    add(0, 0);
    for (int i = 0; i < n; i++){
        x = rects[i].x;
        y = rects[i].y;
        a = rects[i].a;
        ll temp = x * y - a + query(y);
        res = max(res, temp);
        add(-x, temp);
    }
    cout << res << endl;
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