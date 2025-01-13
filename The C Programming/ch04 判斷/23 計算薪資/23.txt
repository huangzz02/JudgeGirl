#include <stdio.h>

int main(){
    
    int t;
    scanf("%d", &t);
    
    if (t <= 60) {
        printf("%d\n", t * 100);
    } else if (t <= 75) {
        printf("%d\n", 60 * 100 + (t - 60) * 125);
    } else {
        printf("%d\n", 60 * 100 + 15 * 125 + (t - 75) * 175);
    }
    
    return 0;
}