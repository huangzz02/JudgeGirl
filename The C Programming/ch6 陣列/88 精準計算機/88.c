#include <stdio.h>

int main(){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    
    int integer = a / b;
    int temp = a % b;
    char reminder[10001];
    
    for (int i = 0; i < n; i++) {
        temp *= 10;
        reminder[i] = temp / b + '0';
        temp %= b;
    }
    reminder[n] = '\0';
    
    printf("%d.%s", integer, reminder);
    
    return 0;
}