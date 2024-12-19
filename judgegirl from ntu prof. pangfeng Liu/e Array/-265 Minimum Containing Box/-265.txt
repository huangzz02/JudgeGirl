#include <stdio.h>
#include <limits.h>

int main() {
    int x, y;
    int xMax = INT_MIN, xMin = INT_MAX, yMax = INT_MIN, yMin = INT_MAX;
    while(scanf("%d %d", &x, &y) != EOF) {
        if(x > xMax) xMax = x;
        if(x < xMin) xMin = x;
        if(y > yMax) yMax = y;
        if(y < yMin) yMin = y;
    }

    printf("%d\n", (xMax - xMin) * (yMax - yMin));
    
    return 0;
}