#include <stdio.h>

int ways(int r, int c) {
    if (r == 1 || c == 1) {
        return 1;
    }
    return ways(r - 1, c) + ways(r, c - 1);
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    printf("%d\n", ways(r, c));
    return 0;
}