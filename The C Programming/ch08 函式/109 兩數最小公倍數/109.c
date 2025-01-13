#include <stdio.h>

//lcm.h
int lcm(int a, int b);

//lcm.c
int lcm(int a, int b) {
    int ori_a = a, ori_b = b;
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (ori_a / a) * ori_b; // prevent overflow
}

//main.c
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int result = lcm(m, n);
    printf("%d", result);
    return 0;
}