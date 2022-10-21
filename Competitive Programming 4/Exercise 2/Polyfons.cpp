#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Point {
public:
    long long  x, y, i;
    Point(ll xx = 0, ll yy = 0): x(xx), y(yy) {}
};

bool operator<(const Point&a, const Point &b){
    if (a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

ll get(const Point &a, const Point &b, const Point &c){
    Point v1(b.x - a.x, b.y - a.y), v2(c.x - b.x, c.y - b.y);
    return v1.x * v2.y - v1.y * v2.x;
}

int main(){
    ll n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].i = 0;
    }
    ll m; 
    cin >> m;
    p.resize(n + m);
    for (int i = 0; i < m; i++){
        cin >> p[n+i].x >> p[n+i].y;
        p[n+i].i = 1;
    }
    sort(p.begin(), p.end());
    Point p0 = p[0], p1 = p.back();
    vector<Point> up(1, p0), down(1, p0);
    for (int i = 1; i < p.size(); i++){
        if (get(p[i], p0, p1) <= 0) { // down
            while(down.size() >= 2 && get(down[down.size() - 2], down.back(), p[i]) < 0){
                down.pop_back();
            }
            down.push_back(p[i]);
        }

        if (get(p[i], p0, p1) >= 0) {
            while(up.size() >= 2 && get(up[up.size() - 2], up.back(), p[i]) > 0){
                up.pop_back();
            }
            up.push_back(p[i]);
        }
    }

    up.push_back(p1);
    down.push_back(p1);

    for (int i = 0; i < down.size(); i++){
        if (down[i].i == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 0; i < up.size(); i++){
        if (up[i].i == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}