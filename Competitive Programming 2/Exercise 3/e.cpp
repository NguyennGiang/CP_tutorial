
/*
  -- gọi buy[w] và sell[w] là số tờ tiền tối thiểu của bà mua và bà bán phải trả;
  buy[0] = 0;
  sell[0] = 0;
  giả sử sell[i] = buy[i] = INT_MAX;
  
  // coin = {5, 10, 20, 50, 100, 200};
  gs for 1 : 6:
    for j = sum --> 1;
    voi w --> buy[j] = so luong be nhat khi dung den k dong tien từ thứ 1 đến thứ i;
    num[1] = 1
    nếu em bớt đi 1 đồng thứ i thì cần nhiều tờ thứ i + 1 hơn;
    
      for k = 0 : num[i]
      buy[j]= min(bụy[j], k + buy[j - k * coins[i]]);
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
const int MAX_NUM = 999999;
const int coins[7] = {0, 5, 10, 20, 50, 100, 200};

int main(){
  while (1){
    int num[7];
    for (int i = 1; i <= 6; i++){
      cin >> num[i];
    }
    int sum = 0;
    for (int i = 1; i <= 6; i++){
      sum += num[i] * coins[i];
    }
    if (sum == 0) break;
    sum = 1000;
    float w;
    cin >> w;
    int wt = int(w * 100 + 0.5);
    int buy[N], sell[N];
    buy[0] = sell[0] = 0;
    for (int i = 1; i <= sum; i++){
      buy[i] = sell[i] = MAX_NUM;
    }
    for (int i = 1; i <= 6; i++){
      for (int j = sum; j > 0; j--){
        for (int k = 0; k * coins[i] <= j; k++){
          sell[j] = min(sell[j], k + sell[j-k*coins[i]]);
        }
      }
    }
    for (int i = 1; i <= 6; i++){
      for (int j = sum; j > 0; j--){
        for (int k = 0; k <= num[i] && k * coins[i] <= j; k++){
          buy[j] = min(buy[j], k + buy[j-k*coins[i]]);
        }
      }
    }
    int res = INT_MAX;
    for (int i = wt; i <= sum; i++){
      res = min(res, buy[i] + sell[i-wt]);
    }
    printf("%3d\n", res);
  }
  return 0;
}
