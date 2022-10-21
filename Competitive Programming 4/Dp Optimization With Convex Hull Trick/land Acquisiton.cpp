#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
const int N = 50005;

ll ans[N];

struct Line {
    ll m, c;

    ll eva(ll x){
        return m * x + c;
    }

    long double intersecX(Line l){
        return (long double) (c - l.c) / (l.m - m);
    }
};

vector<pii> work(vector<pii> v){
    vector<pii> ret;
    sort(v.begin(), v.end(), [](pii a, pii b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    // for (int i = 0; i < v.size(); i++) cout << v[i].first << ' ' << v[i].second << endl;

    for (auto p : v){
        while(!ret.empty() && ret.back().first <= p.first) ret.pop_back();
        ret.push_back(p);
    }
    return ret;
}


int main(){
    int n;
    cin >> n;
    vector<pii> in(n);
    for (int i = 0; i < n; i++) cin >> in[i].first >> in[i].second;

    in = work(in);
    n = in.size();

     ans[0] = 0;
     deque<Line> dp;
     dp.push_back({in[0].first, 0});
     for (int i = 1; i <= n; i++){
        while(dp.size() >= 2 && dp[0].eva(in[i-1].second) >= dp[1].eva(in[i-1].second)) dp.pop_front();
        ans[i] = dp[0].eva(in[i-1].second);

        if (i < n){
            Line cur = {in[i].first, ans[i]};
            while(dp.size() >= 2 && dp.back().intersecX(dp[dp.size() - 2]) >= cur.intersecX(dp[dp.size() - 2])) dp.pop_back();
            dp.push_back(cur);
        }
     }
     cout << ans[n] << endl;
     return 0;
}
