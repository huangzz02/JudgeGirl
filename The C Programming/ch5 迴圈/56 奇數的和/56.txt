#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int sum = 0;
        for (int j = a; j <= b; j++) {
            if (j % 2 != 0) {
                sum += j;
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}