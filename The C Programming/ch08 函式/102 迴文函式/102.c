#include <stdio.h>

//isPalindrome.h
void isPalindrome(int x);

//isPalindrome.c
void isPalindrome(int x) {
    if (x < 0) {
        printf("false\n");
        return;
    }

    int ori_x = x, y = 0;
    while (x > 0) {
        y = y*10 + x%10;
        x /= 10;
    }

    if (ori_x == y) printf("true\n");
    else printf("false\n");
}

//main.c
int main() {
    int x;
    scanf("%d", &x);
    isPalindrome(x);
    return 0;
}