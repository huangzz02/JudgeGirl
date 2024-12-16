#include <stdio.h>

int main(){
    int sum = 0;
    
    while (1) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        if (n % 2 != 0) {
            sum += 1;
        }
    }
    printf("%d\n", sum);
    
    return 0;
}