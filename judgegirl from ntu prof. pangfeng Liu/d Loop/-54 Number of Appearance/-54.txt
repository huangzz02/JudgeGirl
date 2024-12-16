#include <stdio.h>

int main() {
    char n[3], m[8];
    scanf("%s %s", n, m);
    
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (n[0] == m[i]) {
            if (n[1] == m[i + 1]) {
                count++;
            }
        }
    }
    printf("%d", count);

    return 0;
}