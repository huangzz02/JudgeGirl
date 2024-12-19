#include <stdio.h>

// intersection.h
void intersection(int map[100][100], int result[4]);

// intersection.c
void intersection(int map[100][100], int result[4]){
    for (int i = 0; i < 4; i++) {
        result[i] = 0;
    }

    int count;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            count = 0;
            if (map[i][j] == 0) continue;

            if (i - 1 >= 0 && map[i - 1][j] == 1) count++;
            if (i + 1 < 100 && map[i + 1][j] == 1) count++;
            if (j - 1 >= 0 && map[i][j - 1] == 1) count++;
            if (j + 1 < 100 && map[i][j + 1] == 1) count++;

            if (count == 4) result[0]++;
            else if (count == 3) result[1]++;
            else if (count == 2 && 
                    !((i - 1 >= 0 && i + 1 < 100 && map[i - 1][j] == map[i + 1][j]) ||
                      (j - 1 >= 0 && j + 1 < 100 && map[i][j - 1] == map[i][j + 1]))) result[2]++;
            else if (count == 1) result[3]++;
        }
    }
    return;
}

// main.c
int main() {
    int map[100][100];
    int result[4];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    intersection(map, result);

    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
    printf("%d\n", result[2]);
    printf("%d\n", result[3]);

    return 0;
}