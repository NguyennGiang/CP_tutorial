#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int a){
    if (a % 4 != 0){
        return false;
    }
    if (a % 400 == 0){
        return true;
    }
    if (a % 100 == 0){ 
        return false;
    }
    return true;
}

bool isDate(int d, int m, int y){
    if (d == 0 || d > 31 || m == 0 || m > 12 || y < 2000){
        return false;
    }
    switch(m){
        case 1:
        case 3:
        case 5: 
        case 7:
        case 8:
        case 10:
        case 12:
            return d <= 31;
        case 2:
            return d <= (isLeapYear(y) ? 29 : 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return d <= 30;
        default:
            return false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int digit[8];
        int i = 0;
        for (int k = 0; k < 3; k++){
            int n;
            cin >> n;
            while(n > 0){
                digit[i++] = n % 10;
                n /= 10;
            }
        }
        while (i < 8){
            digit[i++] = 0;
        }
        sort(digit, digit + 8);
        
        int count = 0;
        int day = 1000000, month = 1000000, year = 1000000;
        do {
            int d = digit[0] * 10 + digit[1];
            int m = digit[2] * 10 + digit[3];
            int y = digit[4] * 1000 + digit[5] * 100 + digit[6] * 10 + digit[7];
            if (!isDate(d, m, y)){
                continue;
            } 
            count ++;

            if (year == y){
                if (month == m){
                    if (d < day){
                        day = d;
                    }
                }
                else if (m < month){
                    month = m;
                    day = d;
                }
            }
            else if (year > y){
                year = y;
                month = m;
                day = d;
            }
        } while(next_permutation(digit, digit + 8));    

        if (count == 0){
            cout << "0\n";
        }
        else {
           printf("%d %02d %02d %d", count, day, month, year);
        }
    }
    return 0;
}