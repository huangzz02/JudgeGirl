#include <stdio.h>
#include <stdbool.h>

int l, m;
int field[100][100] = {0};
int L_shapedBorder;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < l && y < l &&
           !(x >= L_shapedBorder && y >= L_shapedBorder);
}

void solve(int type, int x, int y, int field[100][100]) {
    if (type == 1) {
        if (check(x, y) && field[x][y] == 1 && field[x + 1][y] == 1 && field[x][y + 1] == 1) {
            printf("1 %d %d\n", x + 1, y + 1);

            field[x][y] = 0;
            field[x + 1][y] = 0;
            field[x][y + 1] = 0;

            solve(4, x - 1, y + 2, field);
            solve(1, x - 1, y - 1, field);
            solve(2, x + 2, y - 1, field);
        } else {
            return;
        }
    } else if (type == 2) {
        if (check(x, y) && field[x][y] == 1 && field[x - 1][y] == 1 && field[x][y + 1] == 1) {
            printf("2 %d %d\n", x, y + 1);

            field[x][y] = 0;
            field[x - 1][y] = 0;
            field[x][y + 1] = 0;

            solve(3, x + 1, y + 2, field);
            solve(2, x + 1, y - 1, field);
            solve(1, x - 2, y - 1, field);
        } else {
            return;
        }
    } else if (type == 3) {
        if (check(x, y) && field[x][y] == 1 && field[x - 1][y] == 1 && field[x][y - 1] == 1) {
            printf("3 %d %d\n", x, y);

            field[x][y] = 0;
            field[x - 1][y] = 0;
            field[x][y - 1] = 0;

            solve(4, x - 2, y + 1, field);
            solve(3, x + 1, y + 1, field);
            solve(2, x + 1, y - 2, field);
        } else {
            return;
        }
    } else {
        if (check(x, y) && field[x][y] == 1 && field[x + 1][y] == 1 && field[x][y - 1] == 1) {
            printf("4 %d %d\n", x + 1, y);

            field[x][y] = 0;
            field[x + 1][y] = 0;
            field[x][y - 1] = 0;

            solve(3, x + 2, y + 1, field);
            solve(4, x - 1, y + 1, field);
            solve(1, x - 1, y - 2, field);
        } else {
            return;
        }
    }
}

int main() {
    scanf("%d %d", &l, &m);
    
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (i < l - m || j < l - m) field[i][j] = 1;
        }
    }

    int size = l;
    int x = size / 2 - 1;
    int y = size / 2 - 1;
    L_shapedBorder = size / 2;
    
    while (size / 2 >= m) {
        solve(1, x, y, field);
        size /= 2;
        x += size / 2;
        y += size / 2;
        L_shapedBorder += size / 2;
    }

    return 0;
}
/*
    Score: Wrong Answer 40

    Solution:
        Slightly improved the logic from version 2.

        First cut it into many L-shaped pieces according to the size,
        with the cutout at the upper right corner (similar to type 1).
        Then do the recursive program for each L-shaped field starting from the center.

    Example:
        Input:
            16 1

        Field:
            First (Record initial field):
                ...
                0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...

                then it will be cut into 4 parts (or in other words, execute 4 times):

                part 1: (l = 16, m = 8)                   part 2: (l = 8, m = 4)                    part 3: (l = 4, m = 2)                    part 4: (l = 2, m = 1)
                ...                                       ...                                       ...                                       ...
                0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ...

            Then execute recursion for all blocks until the end:
                part 1: wrong
                part 2: correct
                part 3: correct
                part 4: correct

    Problem:
        Although the program can work correctly for 2x2, 4x4, 8x8 L-shaped graphics,
        it will still go wrong for 16x16 or other larger graphics like the version 2.
*/