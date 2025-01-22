#include <stdio.h>

int is_able_to_make(int D, int a, int b, int c, int A, int B, int C, int x, int y, int z) {
    long long sum = (long long)A * x + (long long)B * y + (long long)C * z;
    
    if (sum == D) {
        return 1;
    }
    
    if (sum > D) {
        return 0;
    }
    
    if (x < a) {
        if (is_able_to_make(D, a, b, c, A, B, C, x + 1, y, z)) {
            return 1;
        }
    }
    
    if (y < b) {
        if (is_able_to_make(D, a, b, c, A, B, C, x, y + 1, z)) {
            return 1;
        }
    }
    
    if (z < c) {
        if (is_able_to_make(D, a, b, c, A, B, C, x, y, z + 1)) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int D, a, b, c, A, B, C;
        scanf("%d %d %d %d %d %d %d", &D, &a, &b, &c, &A, &B, &C);

        /*
            Ax + By + Cz = D
            0 <= x <= a
            0 <= y <= b
            0 <= z <= c

            find x, y, z
        */

        if (is_able_to_make(D, a, b, c, A, B, C, 0, 0, 0)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}