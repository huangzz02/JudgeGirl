#include <stdio.h>
#include <stdlib.h>

int is_turn(int **arr, int i, int j, int n) {
    if (i - 1 >= 0 && i + 1 < n && arr[i - 1][j] == arr[i + 1][j] ||
        j - 1 >= 0 && j + 1 < n && arr[i][j - 1] == arr[i][j + 1]) {
        return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int intersection = 0;
    int t_junction = 0;
    int turn = 0;
    int dead_end = 0;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count = 0;
            if (arr[i][j] == 0) continue;

            if (i - 1 >= 0 && arr[i - 1][j] == 1) count++;
            if (i + 1 < n && arr[i + 1][j] == 1) count++;
            if (j - 1 >= 0 && arr[i][j - 1] == 1) count++;
            if (j + 1 < n && arr[i][j + 1] == 1) count++;

            if (count == 4) intersection++;
            else if (count == 3) t_junction++;
            else if (count == 2 && is_turn(arr, i, j, n)) turn++;
            else if (count == 1) dead_end++;
        }
    }

    printf("%d\n%d\n%d\n%d\n", intersection, t_junction, turn, dead_end);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}