#include <stdio.h>
#include <stdlib.h>

void dfs(int** image, int imageSize, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageSize) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, imageSize, r - 1, c, oldColor, newColor);
    dfs(image, imageSize, r + 1, c, oldColor, newColor);
    dfs(image, imageSize, r, c - 1, oldColor, newColor);
    dfs(image, imageSize, r, c + 1, oldColor, newColor);
}
 
void floodFill(int** image, int imageSize, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return;

    dfs(image, imageSize, sr, sc, oldColor, newColor);
}
 
int main() {
    int n;
    int sr, sc, newColor;
    scanf("%d", & n);
    int** p = NULL;
    p = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            scanf("%d", &tmp);
            p[i][j] = tmp;
        }
    }
    scanf("%d", &sr);
    scanf("%d", &sc);
    scanf("%d", &newColor);
    floodFill(p, n, sr, sc, newColor);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
    return 0;
}