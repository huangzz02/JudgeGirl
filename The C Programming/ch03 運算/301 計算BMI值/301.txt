#include <stdio.h>

int main(){
    double h, w;
    scanf("%lf\n%lf", &h, &w);
    h = h / 100;
    printf("%.2f\n", w / (h * h));
    
    return 0;
}