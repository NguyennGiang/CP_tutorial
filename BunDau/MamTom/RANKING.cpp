#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, a[MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    sort(a, a+n, greater<int>());

    long long sumScore = 0, score = 1;
    for(int i = 0; i < n; ++i) {
        if (i > 0 && a[i] < a[i-1])
            ++score;
        sumScore += score;
    }

    printf("%lld", sumScore);

    return 0;
}
