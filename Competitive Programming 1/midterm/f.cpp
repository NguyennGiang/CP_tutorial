#include <bits/stdc++.h>
#define ll long long

using namespace std; 

long long findMaxSUm(int a[], int n){
    
    //array for mainting left and right count;
    ll CL[n] = {0}; 
    ll CR[n] = {0};

    // stack for storing the indexs
    stack <int> q;


    //left count
    for (int i = 0; i < n; i++){
        while(q.size() != 0 && a[q.top()] <= a[i]){
            CL[i] += CL[q.top()] + 1; 
            q.pop();
        }
        q.push(i);
    }
    

    // clear the stack

    while(q.size() != 0){
        q.pop();
    }
        
    // right count

    for (int i = n - 1; i >= 0; i--){
        while(q.size() != 0 && a[q.top()] < a[i]){
            CR[i] += CR[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }
  
    // clear the stack 

    ll ans = 0; 
    for (int i = 0; i < n; i++){
        ans += (CL[i] + 1) * (CR[i] + 1) * a[i];
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n; 
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll ans = findMaxSUm(a, n);
    cout << ans;
    return 0;

}