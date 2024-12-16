#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int data[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    int check[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int is_peak = 1;
            for (int k = 0; k < 4; k++) {
                int check_i = i + check[k][0];
                int check_j = j + check[k][1];

                if (check_i >= 0 && check_i < r &&
                    check_j >= 0 && check_j < c   ) {
                    if (data[i][j] <= data[check_i][check_j]) {
                        is_peak = 0;
                        break;
                    }
                }
            }
            if (is_peak) printf("%d\n", data[i][j]);
        }
    }
    return 0;
}