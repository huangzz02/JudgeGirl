#include <stdio.h>

void find_start(int test_case, int w, int d, int *i, int *j, int move_arr[]) {
    if (test_case < w) { // go up
        *i = d - 1;
        *j = test_case;
        move_arr[0] = 1;
    } else if (test_case < (w + d)) { // go left
        *i = d - (test_case - (w - 1));
        *j = w - 1;
        move_arr[2] = 1;
    } else if (test_case < (w*2 + d)) { // go down
        *i = 0;
        *j = w - (test_case - (w+d - 1));
        move_arr[1] = 1;
    } else { // go right
        *i = (test_case - (w*2+d));
        *j = 0;
        move_arr[3] = 1;
    }
}

void find_next(int w, int d, int mirror_arr[][w], int *i, int *j, int move_arr[]) {
    int end = 0;
    while (!end) {
        if (mirror_arr[*i][*j] == 1) {
            if (move_arr[0]) {
                move_arr[0] = 0; 
                move_arr[3] = 1; // up to right
            } else if (move_arr[1]) {
                move_arr[1] = 0;
                move_arr[2] = 1; // down to left 
            } else if (move_arr[2]) {
                move_arr[2] = 0;
                move_arr[1] = 1; // left to down
            } else if (move_arr[3]) {
                move_arr[3] = 0;
                move_arr[0] = 1; // right to up
            }
        }

        if (move_arr[0]) { // go up
            if (*i == 0) {
                end = 1;
                break;
            } else {
                (*i)--;
            }
        } else if (move_arr[1]) { // go down
            if (*i == (d-1)) {
                end = 1;
                break;
            } else {
                (*i)++;
            }
        } else if (move_arr[2]) { // go left
            if (*j == 0) {
                end = 1;
                break;
            } else {
                (*j)--;
            }
        } else if (move_arr[3]) { // go right
            if (*j == (w-1)) {
                end = 1;
                break;
            } else {
                (*j)++;
            }
        }
    }
    
}

int find_end(int w, int d, int i, int j, int move_arr[]) {
    int num_found;

    if (move_arr[1]) { // go down
        num_found = j; 
    } else if (move_arr[3]) { // go right
        num_found = (w - 1) + (d - i);
    } else if (move_arr[0]) { // go up
        num_found = (w+d - 1) + (w - j);
    } else if (move_arr[2]) { // go left
        num_found = (w*2+d) + i;
    }

    return num_found;
}

int main() {

    // example:
    //
    //    13 12 11 10  9
    // 14  0  /  0  /  0  8  
    // 15  0  0  /  0  0  7
    // 16  /  0  0  /  /  6
    // 17  0  /  /  0  0  5
    //     0  1  2  3  4
    //
    // 1 refers to "/"

    int w, d;
    scanf("%d %d", &w, &d);

    int mirror_arr[d][w];
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &mirror_arr[i][j]);
        }
    }

    for (int test_case = 0; test_case < (w + d) * 2; test_case++) {
        int i, j;
        int move_arr[4] = {0, 0, 0, 0};
        // {up, down, left, right}

        find_start(test_case, w, d, &i, &j, move_arr);

        find_next(w, d, mirror_arr, &i, &j, move_arr);

        printf("%d\n", find_end(w, d, i, j, move_arr));
    }
    return 0;
}