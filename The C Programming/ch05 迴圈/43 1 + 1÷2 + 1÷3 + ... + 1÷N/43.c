#include <stdio.h>

int main(){
    double n;
    scanf("%lf", &n);
    
    double sum = 0;
    for (double i = 1; i <= n; i++) {
        sum += 1 / i;
    }
    printf("%.2f", sum);
    
    return 0;
}