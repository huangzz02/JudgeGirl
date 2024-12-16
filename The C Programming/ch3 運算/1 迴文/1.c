#include <stdio.h>
#include <string.h>

int palindrome(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char a[5];
    scanf("%s", &a);
    printf("%d\n", palindrome(a));

    return 0;
}