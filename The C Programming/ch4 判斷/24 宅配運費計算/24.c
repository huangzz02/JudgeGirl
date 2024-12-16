#include <stdio.h>

int main(){
    
    int w, d;
    scanf("%d %d", &w, &d);
    
    if (w < 5) {
        if (d < 10) {
            printf("100\n");
        } else {
            printf("%d\n", 100 + d * 10);
        }
    } else if (w <= 10) {
        printf("%d\n", 100 + d * 20);
    } else if (w <= 20) {
        printf("%d\n", 100 + d * 40);
    } else {
        printf("不收件\n");
    }
    
    return 0;
}