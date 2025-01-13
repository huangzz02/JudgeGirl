#include <stdio.h>
#include <math.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int n, i;
        double p;
        scanf("%d %lf %d", &n, &p, &i);

        double numerator, denominator;
        numerator = p * pow(1 - p, i - 1);
        denominator = 1 - pow(1 - p, n);

        printf("%.4f\n", numerator / denominator);
    }
    return 0;
}