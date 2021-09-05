#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int testcase_count;
  scanf("%d", &testcase_count);
  for (int testcase = 1; testcase <= testcase_count; testcase++) {
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = 0;
    priority_queue<long long> values;
    for (int i = 0; i < n; i++) {
      vector<long long> dat(m);
      for (int j = 0; j < m; j++) {
        scanf("%lld", &dat[j]);
      }
      sort(dat.begin(), dat.end());
      for (int j = 0; j < m; j++) {
        long long val = dat[j] + (j*2+1);
        values.push(-val);
      }
      ans -= values.top();
      values.pop();
    }
    printf("Case #%d: %lld\n", testcase, ans);
  }
	return 0;
}