#include <stdio.h>
#include <ctype.h>

int main() {
    char str[10000];
    int count = 0;

    while (fgets(str, sizeof(str), stdin)) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') {
                if ((str[i + 1] == ' ' && str[i + 2] == ' ') ||
                    str[i + 1] == '\n' ||
                    str[i + 1] == '\0') {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}