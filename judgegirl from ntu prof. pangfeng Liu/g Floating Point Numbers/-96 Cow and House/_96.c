#include <stdio.h>
#define pi 3.1415926

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double area = 0;
    area += c * c * pi * 0.75;
    if (c - a > 0) {
        area += (c - a) * (c - a) * pi * 0.25;
    }
    if (c - b > 0) {
        area += (c - b) * (c - b) * pi * 0.25;
    }
    printf("%f\n", area);
    return 0;
}
/*
    "double" cannot be replaced by "float",
    it may cause accuracy issues
*/