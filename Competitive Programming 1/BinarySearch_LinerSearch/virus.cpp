#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int id = 1; id <= T; id++){
        cout << "Data set #" << id << ":" << endl;
        int n;
        cin >> n;
        vector <string> virus;
        for (int i = 0; i < n; i ++){
            string c; 
            cin >> c;
            virus.push_back(c);
        }
        int m;
        cin >> m;
        vector <string> victor;
        for (int i = 0; i < m; i++){
            string c; 
            cin >> c; 
            victor.push_back(c);
        }
        for(int k = 0; k < m; k++){
            bool illegal = false;
            for (int x = 0; x < n; x++){
                for (int i = 0; i < int(victor[k].size()) - int(virus[x].size()) + 1; i++){
                    bool flag = true;
                    for (int j = 0; j < int(virus[x].size()); j++){
                        if ((virus[x][j] == victor[k][i+j]) || (virus[x][j] == '*')) continue;                        
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true) {
                        illegal = true;
                        break;
                    }
                }
                if (illegal) break;
            }
            cout << "Virus #" << k + 1 << ": " ;
            if (illegal) {
                cout << "Nuts. This virus is illegal in Hawaii!" << endl;
            } else {
                cout << "Cool! Victor can take it with him!" << endl;
            }
        }
        cout << endl;

    }
    return 0;
  
}