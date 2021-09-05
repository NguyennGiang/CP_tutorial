#include <bits/stdc++.h>

using namespace std; 

//fuction to find the maximun value j - i such that a[j] > a[i];
int findMaxDiff(int a[], int n){
    // create an neww array of size n;
    int ax[n];

    // ax[j] stores the maximun elenmet in arr[j...n];
    ax[n-1] = a[n-1];
    for (int j = n - 2; j >= 0; j--){
        ax[j] = max(a[j], ax[j+1]);
    }

    int i = 0; 
    int j = 0;
    int diff = 0;  
    while(i < n && j < n){
        if (a[i] < ax[j]){
            diff = max(j - i, diff);
            j++;
        }
        else {
            i++;
        }
    }
    return diff; 
}

int main(){
    int t; 
    cin >> t;
    getchar();
    while(t--){
        string s; 
        cin >> s; 
        int n = s.size();
        int cnt[n + 2];

        memset(cnt, 0, sizeof(cnt));
        // cnt[i] = difference between the number 1 and 0 in array[1...i]; 
        for (int i = 0; i < n; i++){
            if(s[i] == '1') cnt[i+1]++;
            else cnt[i+1]--;

        } 
        for (int i = 1; i <= n; i++){
            cnt[i] = cnt[i] + cnt[i-1];
        }
        

        int diff = numeric_limits<int>::min();
        diff = findMaxDiff(cnt, n + 1);
        cout << diff << endl;
    }
    return 0;
}

