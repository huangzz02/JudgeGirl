#include <stdio.h>

int main(){
    
    int m, w;
    scanf("%d %d", &m, &w);
    
    if (m >= 6 && m <=9) {
        if (w > 120) {
            printf("%d\n", w * 7);
        } else {
            printf("%d\n", w * 5);
        }
    } else {
        if (w > 120) {
            printf("%d\n", w * 5);
        } else {
            printf("%d\n", w * 3);
        }
    } 
    
    return 0;
}