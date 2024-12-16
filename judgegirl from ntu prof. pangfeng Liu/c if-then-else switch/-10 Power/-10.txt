#include <stdio.h>

int main() {
    
    int n, i;
    scanf("%d\n%d", &n, &i);
    
    int ans = 1;
    
    for (int j = 0; j < i; j++) {
        ans *= n;
    }
    
    printf("%d\n", ans);

    return 0;
}