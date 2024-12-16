#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double p;
    scanf("%d %lf", &n, &p);

    // k ^ n = p
    // k = p ^ (1/n)

    // (int)(k + 0.5) is like (int)round(k)

    printf("%d\n", (int)(pow(p, 1.0/n) + 0.5));
    
    return 0;
}