#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a;

int merge(int l, int r, int m){
    vector <int> b(a.begin() + l, a.begin() + m + 1);
    vector <int> c(a.begin() + m + 1, a.begin() + r + 1);
    int nB = m - l + 1, nC = r - m;
    int i = 0, j = 0, k = l;    
    int cnt = 0;

    while (i < nB && j < nC){
        if (b[i] > c[j]){
            a[k++] = c[j++];
        }
        else {
            a[k++] = b[i++];
            cnt += j;   
        }
    }

    while (i < nB){
        a[k++] = b[i++];
        cnt += j;
    }

    while (j < nC){
        a[k++] = c[j++];
    }
    return cnt;
}

int countInversion(int l, int r){
    if (l >= r) return 0;

    int m = (l + r) / 2;

    int countLeft = countInversion(l, m);
    int countRigh = countInversion(m + 1, r);

    int countMid = merge(l, r, m);
    return countLeft + countMid + countRigh;
}

int main(){
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = countInversion(0, n - 1); 
    cout << cnt << endl;
    return 0;
}