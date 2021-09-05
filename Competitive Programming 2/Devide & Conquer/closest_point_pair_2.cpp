#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    int id;

    bool operator<(const Point &p){
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

vector <Point> p;
int fr, to;
double ans = 99999999.9;

double dist(Point a, Point b){
    double dx = 1.0 * (a.x - b.x) * (a.x - b.x);
    double dy = 1.0 * (a.y - b.y) * (a.y - b.y);
    return sqrt(dx + dy);
}

double merge(int l, int m, int r, double d, Point pMid){
    vector <Point> a(p.begin() + l, p.begin() + m + 1);
    vector <Point> b(p.begin() + m + 1, p.begin() + r + 1);
    int nA = m - l + 1;
    int nB = r - m;
    int i = 0, j = 0, k = l;
    while (i < nA && j < nB){
        if (a[i].y < b[j].y){
            p[k++] = a[i++];
        }
        else {
            p[k++] = b[j++];
        }
    }

    while (i < nA){
        p[k++] = a[i++];
    }
    while (j < nB){
        p[k++] = b[j++];
    }

    for (int i = l; i <= r; i++){
        if (abs(p[i].x - pMid.x) >= d) continue;
        for (int j = i + 1; j <= r; j++){
            if (abs(p[i].x - p[j].x) >= d) continue;
            if (p[j].y - p[i].y >= d) break;

            double tmp = dist(p[i], p[j]);

            if (tmp < d){
                d = tmp;
                if (d < ans){
                    ans = d;
                    fr = p[i].id;
                    to = p[j].id;
                }
            }
        }
    }
    return d;
}

double closesetPair(int l, int r){
    if (l >= r) return 99999999;
    
    int m = (l + r) / 2;
    Point pMid = p[m];
    double minLeft = closesetPair(l, m);
    double minRight = closesetPair(m + 1, r);
    double d = min(minLeft, minRight);
    double minMid = merge(l, m, r, d, pMid);
    d  = min(minMid, d);
    return d;
}

int main(){
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p.begin(), p.end());
    double d = closesetPair(0, n - 1);
    cout << fixed << setprecision(6);
    if (fr > to){
        swap(fr, to);
    }
    cout << fr << " " << to <<  " " << ans;
    return 0;
}