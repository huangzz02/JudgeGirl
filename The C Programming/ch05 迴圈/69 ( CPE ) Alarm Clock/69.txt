#include <stdio.h>

int main() {
    while (1) {
        int h1, m1, h2, m2;
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        
        if (h1 == 0 &&
            m1 == 0 &&
            h2 == 0 &&
            m2 == 0   ) {
            break;    
        }
        
        int min_1 = h1 * 60 + m1;
        int min_2 = h2 * 60 + m2;
        
        if (min_1 <= min_2) {
            printf("%d\n", min_2 - min_1);
        } else {
            printf("%d\n", (1440 - min_1) + min_2);
        }
    }
    
    return 0;
}