#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

const int N = 1e5 + 5;
int n;
int h[N], a[N];

int main(){
    KAMEHAMEHA

    while(cin >> n){
        for (int i = 0; i < n; i++){
            cin >> h[i];
            a[i] = h[i];
        }

        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++){
            if(!s.empty()){
                s.top().s = min(s.top().s, h[i]);
            }
            while(!s.empty() && s.top().f <= h[i]){
                pair<int, int> p = s.top();
                s.pop();
                if(!s.empty()){
                    s.top().s = min(s.top().s, p.s);
                }
            }
            if (!s.empty()){
                a[i] = min(a[i], h[i] - s.top().s);
            }
            s.push({h[i], h[i]});
        }
        while (!s.empty()){
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--){
            if (!s.empty()){
                s.top().s  = min(s.top().s, h[i]);
            }
            while(!s.empty() && s.top().f <= h[i]){
                pair<int, int> p = s.top();
                s.pop();
                if(!s.empty()){
                    s.top().s = min(s.top().s, p.s);
                }
            }
            if (!s.empty()){
                a[i] = min(a[i], h[i] - s.top().s);
            }
            s.push({h[i], h[i]});
        }

        int f = 0;
        for (int i = 0; i < n; i++){
            if (a[i] >= 150000){
                if (f++) cout << " ";
                cout << i + 1;
            }
        }
        cout << endl;
    }
    return 0;
}