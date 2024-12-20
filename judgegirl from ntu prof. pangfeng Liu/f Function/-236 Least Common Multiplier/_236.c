#include <stdio.h>

int gcd(int a, int b){
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (a % b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int x, y;
    scanf("%d", &x);
    int ans = 1;
    while (scanf("%d", &y) != EOF) {
        x = lcm(x, y);
    }
    printf("%d\n", x);
    return 0;
}