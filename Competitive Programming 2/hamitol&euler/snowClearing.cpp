#include <bits/stdc++.h>
using namespace std;
#define N 10000

string buff;
double sum;

double get_distance(int x1, int y1, int x2, int y2){
    x1 -= x2, y1 -= y2;
    return sqrt(1.0 * x1 * x1 + 1.0 * y1 * y1);
}

int main(){
    int t;
    cin >> t;
    int a[10];
    while(t--){
        double x, y;
        cin >> x >> y;
        sum = 0;
        getline(cin, buff);
        while(getline(cin, buff)){
            int len = buff.length();
            int k = 0, n = 0;
            if (!len) break;

            while(k < len ){
                if (buff[k] != ' '){
                    int value = 0, sign = 1;
                    if(buff[k] == '-'){
                        sign = -1;
                        k++;
                    }
                    while(k < len && buff[k] != ' '){
                        value = value * 10 + (buff[k++] - '0');
                    }
                    a[n++] = value * sign;
                }
                else {
                    k++;
                }
            }
            sum += get_distance(a[0], a[1], a[2], a[3]) * 2.0;
            
        }
        sum = sum / 20000.0 * 60.0;
        if(sum - int(sum) >= 0.5) sum++;
        int h = (int)sum / 60;
        int m = (int)sum % 60;
        printf("%d:", h);
        if (m < 10){
            printf("0%d", m);       
        }
        else {
            printf("%d", m);
        }
        cout << endl;
    } 
    return 0;
}