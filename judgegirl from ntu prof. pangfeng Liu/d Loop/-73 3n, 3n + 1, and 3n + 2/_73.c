#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int is_3n = 0;
    int is_3n_1 = 0;
    int is_3n_2 = 0;
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 3 == 0) {
            is_3n++;
        } else if (num % 3 == 1) {
            is_3n_1++;
        } else {
            is_3n_2++;
        }
    }
    
    printf("%d %d %d\n", is_3n, is_3n_1, is_3n_2);
    
    return 0;
}