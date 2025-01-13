#include <stdio.h>

int main() {
    char a, c;
    int b;
    scanf(" %c%d%c", &a, &b, &c);

    if (a == '+') {
        c = c - 'A' + b;
    } else if (a == '-') {
        c = c - 'A' - b;
    }  

    if (c < 0) {
        c += 26;
    } else if (c >= 26) {
        c -= 26;
    }

    printf("%c\n", c + 'A');
    return 0;
}