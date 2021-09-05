#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n; 
    pair <int, int> level[1005];
    int remain[1005];
    cin >> t; 
    for (int i = 1; i <= t; i++){
        cin >> n; 
        for (int j = 0; j < n; j++){
            cin >> level[j].f >> level[j].s;
            remain[j] = 2; 
        }
        int star = 0; 
        int step = 0;
        while (star < 2 * n)
        {
            while (1)
            {
                bool check = false;
                for (int j = 0; j < n; j++){
                    if (remain[j] > 0 && star >= level[j].s){
                        star += remain[j];
                        remain[j] = 0;
                        step++;
                        check = true;
                    }
                }
                if(check == false) {
                    break;
                }
            }
            int tmp = -1; 
            int index; 
            for (int j = 0; j < n; j++){
                if (remain[j] == 2 && star >= level[j].f){
                    if (level[j].s > tmp) {
                        index = j; 
                    }
                    tmp = max(tmp, level[j].s);
                }
            }
            if (tmp > -1) {
                star ++; 
                remain[index]--;
                step++;
            }
            else
                break;
            
        }
        if(star < 2*n)
			cout << "Case #" << i << ": Too Bad" <<endl;
		else
			cout << "Case #" << i << ": " << step << endl;
        
    }
    return 0;
}