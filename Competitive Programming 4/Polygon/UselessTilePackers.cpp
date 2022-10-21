/*
  - xây dựng bao lồi: --> S : công thức <-- các điểm của bao lồi 
  - tính diện tích viên gạch --> P : công thức
  (S - P) * 100 / S 
*/


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

const int N = 105;
int n;
vector<Point> p;

double area(const vector<Point>& p){
    double area = 0;
    for (int j = 0,  i = 0; i < p.size(); i++){
        j = (i + 1) % p.size();
        area += p[i].cross(p[j]);
    }
    return fabs(area / 2.0);
}

void monotone(){
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    vector<Point> up, down;
    
    for (int i = 0; i < n; i++){
        while(up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], p[i]) >= 0){
            up.pop_back();
        }
        up.push_back(p[i]);
        
        while(down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], p[i]) <= 0){
            down.pop_back();
        }
        down.push_back(p[i]);
    }
    
    p = down;
    for (int i = up.size() - 2; i > 0; i--){
        p.push_back(up[i]);
    }
}

int main(){
    int tc = 1;
  while(cin >> n && n != 0){
      cout << "Tile #" << tc++ << endl;
      p.resize(n);
      for (int i = 0; i < n; i++){
          cin >> p[i];
      }
      
      double tile = area(p);
      monotone();
      double con = area(p);
      printf("Wasted Space = %.2f \% \n \n", (con - tile) * 100 / con);
  }
}