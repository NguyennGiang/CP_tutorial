#include <bits/stdc++.h>
#define ll long long;
#define pb push_back

using namespace std;

const int maxn = 1e5;

int cnt[11][maxn];
int h, d, y, s, k, p, g; 

int main() {
    cin >> y; 
    for(int t = 0; t < y; t++)
    {
        cin >> h >> d; 
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < d; i++) {
            cin >> s >> k >> p;
            cnt[k][s]++;
            cnt[k][s + k * p]--;
            }
        
        for (int i = 0; i < 11; i++){
            for (int j = 1; j <= h; j++){
                if (j - i) continue;
                cnt[i][j] = cnt[i][j] + cnt[i][j-i];
            }
        }
        int max = 0;
        for (int j = 0; j <= h; j++){
            int sum = 0;
            for (int i = 0; i < 11; i++){
                sum += cnt[i][j];
            }
            if (sum > max) {
                max = sum;
                g = j;
            }
        }           
        cout << "House " << g << " should get the biggest and best gift next Christmas.\n"; 
    }
    return 0;
}
