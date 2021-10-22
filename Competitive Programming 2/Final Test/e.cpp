#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int tc = 1;
    while (t--){
        int n;
        cin >> n;
        vector <int> height(n), width(n);
        for (int i = 0; i < n; i++) cin >> height[i];
        for (int i = 0; i < n; i++) cin >> width[i];

        vector<int> lis(n + 1), lds(n + 1);
        int increasing = 0, decreasing = 0;

        for (int i = 0; i < n; i++){
            lis[i] = lds[i] = width[i];
            for (int j = 0; j < i; j++){
                if (height[i] < height[j] && lds[i] < lds[j] + width[i]){
                    lds[i] = lds[j] + width[i];
                }
                if (height[i] > height[j] && lis[i] < lis[j] + width[i]){
                    lis[i] = lis[j] + width[i];
                } 
            }
            increasing = max(increasing, lis[i]);
            decreasing = max(decreasing, lds[i]);
        }

     //    for (int i = 0; i < n; i++ ) cout << lds[i] << " ";
        cout << "Case " << tc++ << ". ";
        if (increasing >= decreasing){
            printf("Increasing (%d). Decreasing (%d).\n", increasing, decreasing);
        }
        else printf("Decreasing (%d). Increasing (%d).\n", decreasing, increasing); 
    }
    return 0;
}