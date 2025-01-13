#include <stdio.h>

//ASCII.h
char ascii(char sign, int num, char msg);

//ASCII.c
char ascii(char sign, int num, char msg) {
    num %= 26;
    if (sign == '+') {
        msg += num;
        if (msg > 'Z') msg -= 26;
    } else {
        msg -= num;
        if (msg < 'A') msg += 26;
    }
    return msg;
}

//main.c
int main() {
    char sign,msg;
    int num;
    scanf("%c%d%c", &sign, &num, &msg);
    printf("%c", ascii(sign, num, msg));
 
    return 0;
}