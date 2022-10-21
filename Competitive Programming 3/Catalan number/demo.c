#include <stdio.h>

int main(){
    float x, n;
    scanf("%f %f", &x, &n);

    if (n < 1 || x < 0){
        printf("Error");
    }
    else {
        float sum = 1;
        int p = 1;
        float tmp = x;
        for (int i = 1; i <= n; i++){
            sum = sum + 1.0 * x / p;
            p++;
            x *= tmp;
        }
        printf("%.4f", sum);
    }
    return 0;
}