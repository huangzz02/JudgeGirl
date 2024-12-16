#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        char str[20];
        sprintf(str, "%d", i);
        
        if (i % 5 == 0) {
            continue;
        } else if (i % 7 == 0 || str[strlen(str) - 1] == '7') {
            sum += i * 2;
        } else {
            sum += i;
        }
    }
    printf("%d\n", sum);
    
    return 0;
}