#include <stdio.h>

int find_position(int D, int I) {
    int position = 1;
    for (int i = 0; i < D - 1; i++) {
        if (I % 2 == 0) {
            position = position * 2 + 1;
            I = I / 2;
        } else {
            position = position * 2;
            I = (I + 1) / 2;
        }
    }
    return position;
}

int main() {
    int n;
    scanf("%d", &n);
    int D, I;
    while (1) {
        scanf("%d", &D);
        if (D == -1) break;
        scanf("%d", &I);
        printf("%d\n", find_position(D, I));
    }
    return 0;
}