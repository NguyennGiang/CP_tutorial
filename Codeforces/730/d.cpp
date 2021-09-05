#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=1;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                cout << 0 << endl;
            else
                cout << (i^(i-1)) << endl;
            int v;
            cin >> v;
            if(v==1)
                break;
        }
    }
    return 0;
}