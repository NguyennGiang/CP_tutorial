#include <bits/stdc++.h>
using namespace std;

bool checkEulerPath(vector <int> &outdeg, vector <int> &indeg, vector <bool> &found){
    for (int i = 0; i < 26; i++){
        if(found[i]){
            if (!indeg[i] && !outdeg[i]){ // graph is not connected;
                return false;
            }
        }        
    }

    int nOut = -1, nIn = -1;
    for (int i = 0; i < 26; i++){
        if(outdeg[i] - indeg[i] == 1){
            nOut++;
        }
        else if (indeg[i] - outdeg[i] == 1){
            nIn++;
        }
        else if (indeg[i] != outdeg[i]){
            return false;
        } 
    }
    return nOut <= 1 && nIn <= 1;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> outdeg(26, 0), indeg(26, 0);
        vector <bool> found(26, 0);
        vector <vector <int>> adj(26, vector <int>());
        
        for (int i = 0; i < n; i++){
            string s;
            cin >> s;
            int u = s[0] - 'a';
            int v = s[s.length() - 1] - 'a';
            outdeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            found[u] = found[v] = 1;
        }
        if (checkEulerPath(outdeg, indeg, found)){
            cout << "Ordering is possible.\n";
        }
        else {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}