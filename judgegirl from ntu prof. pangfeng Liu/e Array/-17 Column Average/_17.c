#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int arr[r][c];
    int rev[c][r];
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            rev[j][i] = arr[i][j];
        }
    }
    
    int sum = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sum += rev[i][j];
        }
        printf("%d\n", sum / r);
        sum = 0;
    }
    
    return 0;
}