#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

const int INF = 1e9;
struct Point {
    int x, y;
    int id;
};

bool compareX(const Point &a, const Point &b){
    return a.x < b.x;
}

bool compareY(const Point &a, const Point &b){
    return a.y < b.y;
}

double dist(Point a, Point b){
    double dx = 1.0 * (a.x - b.x) * (a.x - b.x);
    double dy = 1.0 * (a.y - b.y) * (a.y - b.y);
    return sqrt(dx + dy);
}

int dx, dy;
double ans = 999999999.9;

double bruteForce(vector <Point> &points, int l, int r){
    double d = 999999999.9;
    for (int i = l; i <= r; i ++){
        for (int j = i + 1; j <= r; j++){
            double tmp = dist(points[i], points[j]);
            if (tmp < d){
                d = tmp;
                if (d < ans){
                    ans = d;
                    dx = points[i].id;
                    dy = points[j].id;
                }
            }
        }   
    }
    return d;
}       

double closesetPair(vector <Point> &points, int l, int r){
    if (r - l <= 2){
        return bruteForce(points, l, r);
    }
    int m = (l + r) / 2;
    Point pMid = points[m];
    double minLeft = closesetPair(points, l, m);
    double minRight = closesetPair(points, m + 1, r);
    double d = min(minLeft, minRight);

    vector <Point> strip;

    for (int i = l; i <= r; i++){
        if (abs(points[i].x - pMid.x) < d){
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++){
        for (int j = i + 1; j < strip.size(); j++){
            if (strip[j].y - strip[i].y >= d) break; 
            double tmp = dist(strip[i], strip[j]);
            
            if (tmp < d){
                d = tmp;
                if (d < ans){
                    ans = d;
                    dx = strip[i].id;
                    dy = strip[j].id;
                    }

            }            
        }
    }

    return d;
}

int main(){
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    vector <Point> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }

    sort(points.begin(), points.end(), compareX);
    double d = closesetPair(points, 0, n - 1);
    if (dx > dy){
        swap(dx, dy);
    }
    cout << dx << " " << dy << " " << ans;
    return 0;
}