#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    double s, a;
    char str[4];
    while(scanf("%lf %lf %s", &s, &a, &str) == 3) {
        if (strcmp(str , "min") == 0) {
            a /= 60 ;
        }
        double rad = a * (M_PI / 180); // rad = deg * (pi / 180)

        double r = s + 6440;

        double arc, chord;
        arc = (2*r * M_PI) * (a / 360);
        chord = sqrt(r*r + r*r - 2*r*r*cos(rad));

        printf("%.6f %.6f\n", arc, chord);
    }
    
    return 0;
}