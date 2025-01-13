#include <stdio.h>

int in_bounds(int r, int c, int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int arr[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int can = 0;
    int cant = 0;
    
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {0, -1} ,          {0, 1} ,
                            {1, -1} , {1, 0} , {1, 1} };
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 5) {
                
                int check_5 = 0;
                
                for (int d = 0; d < 8; d++) {
                    int ni = i + directions[d][0];
                    int nj = j + directions[d][1];
                    
                    if (in_bounds(r, c, ni, nj)) {
                        if (arr[ni][nj] == 5) {
                            check_5 = 1;
                            arr[ni][nj] = 0;
                        }
                    }
                }
                
                if (check_5) {
                    arr[i][j] = 0;
                    continue;
                }
                
                for (int d = 0; d < 8; d++) {
                    int ni = i + directions[d][0];
                    int nj = j + directions[d][1];
                    
                    if (in_bounds(r, c, ni, nj)) {
                        if (arr[ni][nj] == 1) {
                            arr[ni][nj] = 0;
                            can++;
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 1) {
                cant++;
            }
        }
    }
    
    printf("%d %d\n", can, cant);

    return 0;
}