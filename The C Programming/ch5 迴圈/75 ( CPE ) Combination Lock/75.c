#include <stdio.h>

int main() {
    int start, a, b, c;
    while (1) {
        scanf("%d %d %d %d", &start, &a, &b, &c);
        if (start == 0 && a == 0 && b == 0 && c == 0) break;

        int count = 0;
        count += 720; // step 1
        
        int turn;
        if (start == a) {
            turn = 0;
        } else if (start > a) {
            turn = start - a;
        } else if (start < a ) {
            turn = start + (40 - a);
        }
        // 360 / 40 = 9
        count += turn * 9; // step 2
        
        count += 360; // step 3
        
        if (a == b) {
            turn = 0;
        } else if (a > b) {
            turn = b + (40 - a);
        } else if (a < b ) {
            turn = b - a;
        }
        count += turn * 9; // step 4
        
        if (b == c) {
            turn = 0;
        } else if (b > c) {
            turn = b - c;
        } else if (b < c ) {
            turn = (40 - (c - b));
        }
        count += turn * 9; // step 5

        printf("%d\n", count);
    }
    return 0;
}