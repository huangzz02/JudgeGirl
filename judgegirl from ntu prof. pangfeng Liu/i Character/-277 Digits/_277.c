#include <stdio.h>
#include <string.h>

void add(char data[][101], int row, char num, int h, int w, int start) {
    int i;
    if (row == 0) { // first
        if (num == '1' || num == '4') {
            for (i = 0 + start; i < w + start; i++) {
                data[row][i] = ' ';
            }
        } else {
            data[row][0 + start] = ' ';
            for (i = 1 + start; i < (w - 2) + start; i++) {
                data[row][i] = num;
            }
            data[row][(w - 2) + start] = ' ';
            data[row][(w - 1) + start] = ' ';
        }
    } else if (row < h / 2) { // upper mid
        if (num == '1' || num == '2' || num == '3') {
            data[row][0 + start] = ' ';
        } else {
            data[row][0 + start] = num;
        }
        for (i = 1 + start; i < (w - 2) + start; i++) {
            data[row][i] = ' ';
        }
        if (num == '5' || num == '6') {
            data[row][(w - 2) + start] = ' ';
        } else {
            data[row][(w - 2) + start] = num;
        }
        data[row][(w - 1) + start] = ' ';
    } else if (row == h / 2) { // mid
        if (num == '0' || num == '1' || num == '7') {
            for (i = 0 + start; i < w + start; i++) {
                data[row][i] = ' ';
            }
        } else {
            data[row][0 + start] = ' ';
            for (i = 1 + start; i < (w - 2) + start; i++) {
                data[row][i] = num;
            }
            data[row][(w - 2) + start] = ' ';
            data[row][(w - 1) + start] = ' ';
        }
    } else if (row < h - 1) {  // lower mid
        if (num == '1' || num == '3' || num == '4' || num == '5' || num == '7' || num == '9') {
            data[row][0 + start] = ' ';
        } else {
            data[row][0 + start] = num;
        }
        for (i = 1 + start; i < (w - 2) + start; i++) {
            data[row][i] = ' ';
        }
        if (num == '2') {
            data[row][(w - 2) + start] = ' ';
        } else {
            data[row][(w - 2) + start] = num;
        }
        data[row][(w - 1) + start] = ' ';
    } else {  // last
        if (num == '1' || num == '4' || num == '7' || num == '9') {
            for (i = 0 + start; i < w + start; i++) {
                data[row][i] = ' ';
            }
        } else {
            data[row][0 + start] = ' ';
            for (i = 1 + start; i < (w - 2) + start; i++) {
                data[row][i] = num;
            }
            data[row][(w - 2) + start] = ' ';
            data[row][(w - 1) + start] = ' ';
        }
    }
}

int main() {
    char str[11];
    int w, h;

    while (scanf("%s %d %d", str, &w, &h) != EOF) {
        char data[h][101];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                data[i][j] = ' ';
            }
            data[i][w] = '\0';
        }

        int start = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            for (int row = 0; row < h; row++) {
                add(data, row, str[i], h, w, start);
            }
            start += w;
        }
        for (int i = 0; i < h; i++) {
            data[i][start] = '\0';
        }

        for (int i = 0; i < h; i++) {
            printf("%s\n", data[i]);
        }
    }
    
    return 0;
}
/*
    sample input:
        0123456789 8 7
    sample output:
         00000           22222   33333           55555   66666   77777   88888   99999  
        0     0       1       2       3 4     4 5       6       7     7 8     8 9     9 
        0     0       1       2       3 4     4 5       6       7     7 8     8 9     9 
                         22222   33333   44444   55555   66666           88888   99999  
        0     0       1 2             3       4       5 6     6       7 8     8       9 
        0     0       1 2             3       4       5 6     6       7 8     8       9 
         00000           22222   33333           55555   66666           88888          
*/