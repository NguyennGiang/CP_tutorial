#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

struct block
{
    int l, m;
    block() {};
    block (int l, int m) : l(l), m(m) {}
    bool operator<(const block &other) const {
        return l < other.l || l == other.l && m < other.m;
    }
    bool operator <= (const block &other) {
        return l <= other.l && m <= other.m;
    }
} b[N];

int n;
int lis[N], size;

int main(){
    while (cin >> n && n){
        for (int i = 0; i < n; i++){
            scanf("%d%d", &b[i].l, &b[i].m);
        }
        sort(b, b + n);
        size = 0;
        for (int i = 0; i < n; i++){
            int j = upper_bound(lis, lis + size, b[i].m) - lis;
            if (j == size) size++;
            lis[j] = b[i].m;
        }
        printf("%d\n", size);
    }
    printf("*");
    return 0;
}