#include<bits/stdc++.h>
using namespace std;

struct ss
{
    int pos;
    string s;
    bool operator < (const ss &x)const
    {
        if (x.s == s)return pos > x.pos;
        return s > x.s;
    }
};
priority_queue<ss>que;
typedef struct ss ss;
ss x;
char str[100005];

int k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%s", str + 1);
    scanf("%d", &k);
    
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
    {
        x.s = "";
        x.s += str[i];
        x.pos = i;
        que.push(x);
    }
    
    while (!que.empty())
    {
        k--;
        x = que.top();
        //cout<<k<<" "<<x.s<<endl;
        que.pop();
        if (!k)
        {
            break;
        
        }
        
        if (x.pos<len)
        {
            x.pos++;
            x.s += str[x.pos];
            que.push(x);
        }
        
        
        
        
    }
    if (k) cout << "No such line." << endl;
    else cout << x.s << endl;
}