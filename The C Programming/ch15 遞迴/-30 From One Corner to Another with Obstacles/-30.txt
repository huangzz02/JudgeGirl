#include <stdio.h>

int matrix[12][12];

int ways(int r, int c, int rows, int cols) {
    if (r == 0 && c == cols - 1) {
        return 1;
    }
    if (r < 0 || c < 0 || r >= rows || c >= cols || matrix[r][c] == 0) {
        return 0;
    }
    return ways(r - 1, c, rows, cols) + ways(r, c + 1, rows, cols); // from (r, 0) to (0, c)
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%d\n", ways(r - 1, 0, r, c));
    return 0;
}