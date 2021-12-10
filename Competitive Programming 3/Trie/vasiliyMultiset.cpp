#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7 + 10;
struct Node {
    int num, cnt;
    int next[2];
}p[N];

int id;

void  insert(int n){
    int now = 0;
    for (int i = 31; i >= 0; i--){
        if (!p[now].next[n >> i & 1]) p[now].next[n >> i & 1] = ++id;
        now = p[now].next[n >> i & 1], p[now].cnt++;
    }
    p[now].num = n;
}

void del(int n){
    int now = 0;
    for (int i = 31; i >= 0; i--){
        now = p[now].next[n >> i & 1], p[now].cnt--;
    }
}


int query(int n){
    int now = 0;
    for (int i = 31; i >= 0; i--){
        if (p[p[now].next[n >> i & 1 ^ 1]].cnt) now = p[now].next[n >> i & 1 ^ 1];
        else now = p[now].next[n >> i & 1];
    }
    return n ^ p[now].num;
}

int main(){
    int q;
    cin >> q;
    insert(0);
    char op;
    int x;
    while(q--){
        cin >> op >> x;
        if (op == '+'){
            insert(x);
        }
        else if (op == '-'){
            del(x);
        }
        else {
            cout << query(x) << endl;
        }
    }
    return 0;
}
