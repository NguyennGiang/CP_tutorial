#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8

struct Pt {
    double x, y;
    bool operator<(const Pt &a) const {
        if (x != a.x){
            return x < a.x;
        }
        return y < a.y;
    }
};

double cross(Pt o, Pt a, Pt b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double dist(Pt a, Pt b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calcConvexHull(Pt p[], int n){
    if (n == 1) return 0;
    sort(p, p + n);
    Pt ch[20];
    int m = 0;
    for (int i = 0; i < n; i++){
        while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0){
            m--;
        }
        ch[m++] = p[i];
    }

    for (int i = n - 1, t = m + 1; i >= 0; i--){
        while (m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0){
            m--;
        }
        ch[m++] = p[i];
    }
    m--;
    if (m == 2){
        return 2 * dist(ch[0], ch[1]);
    }
    double bound = 0;
    for (int i = 0, t = m - 1; i < m; t = i++){
        bound += dist(ch[i], ch[t]);
    }
    return bound;
}

int main(){
    int n, m;
    int tc = 0;
    double x[20], y[20], v[20], l[20];
    Pt p[20];
    while(cin >> n && n){
        if (tc) cout << endl;
        for (int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> v[i] >> l[i];
        }

        double mncost = 0xffffff, extraWood;
        int mnstate, mncut;
        for (int i = (1 << n) - 1; i > 0; i--){
            double bound = 0, cost = 0;
            int cut = 0;
            m = 0;
            for (int j = 0; j < n; j++){
                if ((i >> j) & 1){
                    bound += l[j];
                    cost += v[j];
                    cut++;
                }
                else {
                    p[m].x = x[j];
                    p[m].y = y[j];
                    m++;
                }
            }
            if (cost > mncost) continue;
            double tmp = calcConvexHull(p, m);
            if (tmp <= bound + eps){
                if (mncost > cost || (fabs(mncost - cost) < eps && mncut > cut)){
                    mncost = cost;
                    mncut = cut;
                    mnstate = i;
                    extraWood = bound - tmp;
                }
            }
        }
        
        cout << "Forest " << ++tc << endl << " Cut these trees: ";
        for (int i = 0; i < n; i++){
            if ((mnstate >> i) & 1) cout << i + 1 << ' ';
        }
        cout << fixed << setprecision(2);
        cout << endl << "Extra wood: " << extraWood << endl;
    }
    return 0;
}