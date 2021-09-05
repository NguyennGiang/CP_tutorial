#include <bits/stdc++.h>
using namespace std;

const int N = 30;
vector <string> ans;
int indeg[N], outdeg[N];
bool vis[1002][1002];
vector <string> g[N];

void init(){
    for (int i = 0; i < N; i++){
        g[i].clear();
        indeg[i] = 0;
        outdeg[i] = 0;
    }
    
}

void euler(int u){
    for (int i = 0; i < g[u].size(); i ++){
        string v = g[u][i];
        if (!vis[u][i]){
            vis[u][i] = true;
            euler(v[v.length() - 1] - 'a');
            ans.push_back(v);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            string s;
            cin >> s;
            g[s[0] - 'a'].push_back(s);
            outdeg[s[0] - 'a']++;
            indeg[s[s.length() - 1] - 'a']++;
        }
        int check = 0;
        for (int i = 0; i < N; i++){
            if(indeg[i] != outdeg[i]){
                check += abs(indeg[i] - outdeg[i]);
            }
        }
      //  cout << check << endl;
        if (check > 2){
            cout << "***\n";
        }
        else {
            for (int i = 0; i < N; i++){
                sort(g[i].begin(), g[i].end());
            }

            ans.clear();
            int p = 0;
            
            if (check == 0){
                while(!g[p].size()) p++;
            }
            else {
                for (int i = 0; i < N; i++){
                    if(outdeg[i] - indeg[i] == 1){
                        p = i;
                    }
                }
            }
            memset(vis, false, sizeof(vis));
           // cout << p << endl;
            euler(p);
            if (ans.size() != n){
                cout << "***\n";
                continue;
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < n; i++){
                if (i == 0){
                    cout << ans[i];
                }
                else {
                    cout << "." << ans[i];
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
