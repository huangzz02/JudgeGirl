#include <stdio.h>

int cycle_length (int n) {
    int count = 1;
    while (n != 1) {
        if (n % 2 != 0) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
        count++;
    }
    return count;
}

int main(){
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int biggest_cycle_length = 0;
        for (int j = a; j <= b; j++) {
            if (cycle_length(j) > biggest_cycle_length) {
                biggest_cycle_length = cycle_length(j);
            }
        }
        
        printf("%d\n", biggest_cycle_length);
    }
    
    return 0;
}