#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class NewBanknote {
public:
    int f(int X) {
        vector <int> a({1, 2, 5});
        for (int i = 3; i < 15; ++i) a.push_back(a[i - 3] * 10);
        int ans = 0;
        for (int i = 14; i >= 0; --i) {
            ans += X / a[i];
            X %= a[i];
        }
        return ans;
    }
    int calc(int X, int total) {
        int res = total;
        for (int i = 0; i <= 50000; ++i) {
            res = min(res, f(total) + i);
            total -= X;
            if (total < 0) break;
        }
        return res;
    }
    vector <int> fewestPieces(int x, vector <int> a) {
        vector <int> result;
        for (int it : a) result.push_back(calc(x, it));
        return result;
    }
};

ostream& operator << (ostream& cout, vector <int> a) {
    for (int i : a) cout << i << " ";
    return cout;
}

int main() {
    NewBanknote sol;
    int x; cin >> x;
    vector <int> a;
    int tmp;
    while (cin >> tmp) {
        a.push_back(tmp);
    }
    /*1234
    1233 1234 1235
    */
    cout << sol.fewestPieces(x, a) << "\n";
    return 0;
}