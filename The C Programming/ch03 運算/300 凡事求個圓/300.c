#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

int main(){
    int r;
    scanf("%d", &r);
    
    printf("pi=%.5f\n", M_PI);
    printf("radius=%d\n", r);
    printf("circumference=%.5f\n", r * 2 * M_PI);
    printf("area=%.5f\n", r * r * M_PI);
    
    return 0;
}