#include <bits/stdc++.h>

using namespace std; 

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector <bool> oce(n + 1, 0);
        stack <int> people;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            oce[x] = 1;
            if (x > pre) {
                for (int i = pre + 1; i <= x; i++)
                    people.push(i);
                pre = x;
            }
            
            while (!people.empty() && oce[people.top()] == 1) {
                cout << people.top() << ' ';
                people.pop();
            }
        }
        while (!people.empty()) {
                cout << people.top() <<' ';
                people.pop();
            }
        cout << endl;
    }
    return 0;
}