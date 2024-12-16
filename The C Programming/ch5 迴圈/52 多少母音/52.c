#include <stdio.h>
#include <string.h>

int main(){
    char str[300];
    
    scanf("%s", str);
    
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count ++;
        }
    }
    printf("%d\n", count);
    
    return 0;
}