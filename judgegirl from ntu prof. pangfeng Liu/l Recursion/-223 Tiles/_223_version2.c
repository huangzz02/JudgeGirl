#include <stdio.h>
#include <stdbool.h>

int l, m;
int field[100][100] = {0};

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < l && y < l;
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

    solve(1, l - m - 1, l - m - 1, field);

    return 0;
}
/*
    Score: Wrong Answer 30

    Solution:
        Redesigning the recursive structure.

        Started from the center of the field and make note of the types of parts.
        Then let the recursive program find the route down by itself.

    Example:
        Input:
            8 2

        Field:
            First (Record initial field):
                ...
                0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 0 0 0 0 ...
                1 1 1 1 1 1 0 0 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...

            Second:
                ...
                0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 1 1 0 0 0 0 ...
                1 1 1 1 1 0 0 0 0 0 ...
                1 1 1 1 1 0 0 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                (print: 1 6 6, correct)

            Third:
                ...
                0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 0 0 0 0 0 0 ...
                1 1 1 1 0 0 0 0 0 0 ...
                1 1 1 1 1 0 0 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...
                (print: 4 5 7, correct)

            Fourth:
                Actually:                    Expected:
                ...                          ...
                0 0 0 0 0 0 0 0 0 0 ...      0 0 0 0 0 0 0 0 0 0 ...
                0 0 0 0 0 0 0 0 0 0 ...      0 0 0 0 0 0 0 0 0 0 ...
                1 1 1 1 0 0 0 0 0 0 ...      1 1 1 1 0 0 0 0 0 0 ...
                1 1 1 0 0 0 0 0 0 0 ...      1 1 1 1 0 0 0 0 0 0 ...
                1 1 1 0 0 0 0 1 0 0 ...      1 1 1 1 0 0 0 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...      1 1 1 1 0 0 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...      1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...      1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...      1 1 1 1 1 1 1 1 0 0 ...
                1 1 1 1 1 1 1 1 0 0 ...      1 1 1 1 1 1 1 1 0 0 ...
                (print: 1 4 6, wrong)        (print: 1 5 5, correct)

            ... and the rest of the parts are wrong.

    Problem:
        When searching for a route,
        it is easy to go in the wrong direction (especially for larger fields),
        which may cause the route to develop uncontrollably.
*/