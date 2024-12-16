#include <stdio.h>
#include <string.h>

int main() {
    char a[6];
    scanf("%s", a);

    for (int i = 0; i < strlen(a); i++) {
        printf("%c", a[strlen(a) - 1 - i]);
    }

    printf("\n");
    
    return 0;
}