#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    double sum = 0;
    for (double i = 1; i <= n; i++) {
        double sumj = 1;
        for (double j = 1; j <= i; j++) {
            sumj *= j;
        }
        sum += i / sumj;
    }
    printf("%.5f", sum);
    
    return 0;
}