#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, tcase = 0, n, m, x;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int ch[105];
        for (int i = 0; i < m; i++){
            ch[i] = 0;
            for (int j = 0; j < n; j++){
                cin >> x;
                ch[i] |= x << j;

            }
        }

        queue<int> q;
        int step[65536] = {}, one, two;
        q.push((1 << n) - 1);
        step[(1 << n) - 1] = 1;
        while(!q.empty() && step[0] == 0){
            one = q.front(), q.pop();
            for (int i = 0; i < m; i++){
                two = one ^ ch[i];
                if (step[two] == 0){
                    step[two] = step[one] + 1;
                    q.push(two);
                }
            }
        }

        cout << "Case " << ++tcase << ": " << (step[0] == 0 ? "IMPOSSIBLE" : to_string(step[0] - 1)) << endl;
    }
    return 0;
}