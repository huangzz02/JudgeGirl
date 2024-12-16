#include <stdio.h>
#include <string.h>

int main(){
    int a;
    scanf("%d", &a);
    
    int first = 1;
    for (int i = 1; i <= a; i++) {
       int sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (i == sum) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
    
    return 0;
}