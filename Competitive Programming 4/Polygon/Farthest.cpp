#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

const double EPS = 1e-9;

int cmp(double x, double y) {
    return (x < y + EPS) ? -1 : (x > y + EPS);
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    int cmp(const Point &p) const {
        if (x != p.x) return ::cmp(x, p.x);
        return ::cmp(y, p.y);
    }

#define op(x) bool operator x (const Point& p) const { return cmp(p) x 0;}

    op(>)

    op(<)

    op(==)

    op(>=)

    op(<=)

    op(!=)

#undef op

    Point operator+(const Point &p) const {
        return {x + p.x, y + p.y};
    }

    Point operator-(const Point &p) const {
        return {x - p.x, y - p.y};
    }

    Point operator*(double k) const {
        return {x * k, y * k};
    }

    Point operator/(double k) const {
        return {x / k, y / k};
    }

    // dot product
    double dot(const Point &p) const {
        return x * p.x + y * p.y;
    }

    // cross product
    double cross(const Point &p) const {
        return x * p.y - y * p.x;
    }

    double norm() {
        return x * x + y * y;
    }

    double len() {
        return sqrt(norm());
    }
    
    double dis(const Point p) const {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    
    Point rotate(double alpha) const {
        double cosa = cos(alpha), sina = sin(alpha);
        return {x * cosa - y * sina, x * sina + y * cosa};
    }
};

int ccw(Point a, Point b, Point c){
    return cmp((b-a).cross(c-a), 0);
}

istream& operator>> (istream& is, Point& p){
  return is >> p.x >> p.y;
}

double dist(Point a, Point b){
  return a.dis(b);
}

double BS(vector<Point> & p, Point a){
  int l = 0, r = p.size() - 1;
  double maxx = 0.0f;
  while(l <= r){
    int m = (l + r) / 2;
    double left = m - 1 < 0 ? 0 : dist(p[m - 1], a);
    double mid = dist(p[m], a);
    double right = m + 1 >= p.size() ? 0 : dist(p[m + 1], a);
    //cout << m <<' '<<left <<' '<<mid <<' '<<right << endl;
    if (mid > maxx){
      maxx = mid;
    }
    
    if (right > mid){
        l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return maxx;
}

void monotone(vector<Point> &G, vector<Point> &M){
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    vector<Point> up, down;
    
    for (int i = 0; i < G.size(); i++){
        while(up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], G[i]) >= 0){
            up.pop_back();
        }
        up.push_back(G[i]);
        
        while(down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], G[i]) <= 0){
            down.pop_back();
        }
        down.push_back(G[i]);
    }
   
    double ans = 0.0f;
    for (int i = 0; i < M.size(); i++){
      double dis = BS(up, M[i]);
      ans = max(dis, ans);
    }
    
    for(int i = 0; i < M.size(); i++){
      double dis = BS(down, M[i]);
      ans = max(ans, dis);
    }
    cout << int(ans) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
      int n; cin >> n;
      vector<Point> G, M;
      for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0){
          M.push_back(Point(a, b));
        }
        else {
          G.push_back(Point(a, b));
        }
      }
      monotone(G, M);
    }
    return 0;
}