#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        int max = 0;
        int min = 0;
        
        for (int j = 0; j < n; j++) {
            int store;
            scanf("%d", &store);
            if (j == 0) {
                max = store;
                min = store;
            }
            
            if (store > max) {
                max = store;
            }
            if (store < min) {
                min = store;
            }
        }
        
        printf("%d\n", (max - min) * 2);
    }
    
    return 0;
}