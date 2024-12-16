#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int surface_area = 2 * (a * b + b * c + c * a)
                     + 8 * ((  (a - e * 2) 
                             + (b - e * 2) 
                             + (c - e * 2)) * d);
                       
    int volume = a * b * c 
               - 2 * (a - e * 2) * (b - e * 2) * d 
               - 2 * (b - e * 2) * (c - e * 2) * d 
               - 2 * (c - e * 2) * (a - e * 2) * d;
    
    printf("%d\n%d\n", surface_area, volume);

    return 0;
}