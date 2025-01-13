#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int count = 0;
    int distance = a - b;
    
    while (distance > 0) {
        count++;
        distance -= c;
        if (distance <= 0) {
            break;
        } else {
            distance += d;
        }
    }
    
    printf("%d", count);
    
    return 0;
}