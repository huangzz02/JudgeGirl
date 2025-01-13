#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double p;
    scanf("%d %lf", &n, &p);

    // k ^ n = p
    // n * ln(k) = ln(p)
    // ln(k) = ln(p) / n
    // k = e ^ (ln(p) / n)

    // (int)(k + 0.5) is like (int)round(k)

    printf("%d\n", (int)(exp(log(p) / n) + 0.5));
    
    return 0;
}