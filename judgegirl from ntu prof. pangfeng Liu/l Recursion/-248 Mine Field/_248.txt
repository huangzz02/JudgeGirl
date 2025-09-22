#include <stdio.h>
#include <string.h>

#define N 9 // 9x9

int A[N][N]; // input matrix, number of mines in each 3x3 grid
int B[N][N]; // output matrix, stores mine distribution (0 or 1)
int current_sum[N][N]; // current number of placed mines in each 3x3 grid
int remaining[N][N]; // number of undecided cells in each 3x3 grid
int solved = 0; // flag to indicate if a solution has been found

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", B[i][j]);
            if (j < N - 1) printf(" "); // Important: avoid trailing space
        }
        printf("\n");
    }
}

// Backtracking function, pos indicates the current cell number (0 to 80)
void bt(int pos) {
    if (solved) return; // If a solution has been found, exit
    if (pos == N * N) { // If all cells have been processed
        print_grid();
        solved = 1;     // Mark that a solution has been found
        return;
    }
    int r = pos / N; // Current cell's row
    int c = pos % N; // Current cell's column

    // Try placing a mine (val=1) or not placing (val=0)
    for (int val = 0; val < 2; val++) {
        int ok = 1; // Flag to indicate if the current choice is feasible

        // Check if the 3x3 grid centered at (r,c) satisfies the constraints
        for (int dr = -1; dr <= 1 && ok; dr++) {
            for (int dc = -1; dc <= 1 && ok; dc++) {
                int kr = r + dr; // Row in the 3x3 grid
                int kc = c + dc; // Column in the 3x3 grid
                if (kr < 0 || kr >= N || kc < 0 || kc >= N) continue; // Out of bounds check
                int new_cur = current_sum[kr][kc] + val; // Current number of mines after placing
                int new_rem = remaining[kr][kc] - 1;     // Remaining undecided cells

                // Check if constraints are violated
                if (new_cur > A[kr][kc]) {
                    ok = 0; // Current number of mines exceeds input constraint
                    continue;
                }
                if (new_rem == 0) { // If all cells in the 3x3 grid have been decided
                    if (new_cur != A[kr][kc]) ok = 0;
                    /*
                        If all cells are decided, the number of mines must match the input exactly.
                    */
                } else {
                    if (new_cur + new_rem < A[kr][kc]) ok = 0; // Pruning
                    /*
                        Imagine you need to gather 5 mines,
                        but you currently only have 2,
                        and there is 1 square left.
                        Even if you place a mine in that square,
                        it will only make 3 out of 5,
                        so this route cannot succeed.
                    */
                }
            }
        }

        if (ok) { // If the current choice is feasible
            B[r][c] = val; // Set the current cell's mine status

            // Update current_sum and remaining in the 3x3 grid
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int kr = r + dr;
                    int kc = c + dc;
                    if (kr >= 0 && kr < N && kc >= 0 && kc < N) {
                        current_sum[kr][kc] += val; // Update mine count
                        remaining[kr][kc]--;        // Decrease undecided cell count
                    }
                }
            }

            bt(pos + 1); // Recursively process the next cell

            // Backtrack: Restore state
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int kr = r + dr;
                    int kc = c + dc;
                    if (kr >= 0 && kr < N && kc >= 0 && kc < N) {
                        current_sum[kr][kc] -= val; // Restore mine count
                        remaining[kr][kc]++;        // Restore undecided cell count
                    }
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    memset(current_sum, 0, sizeof(current_sum));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            // Calculate the number of cells in the 3x3 grid centered at (i,j)
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int ni = i + dr;
                    int nj = j + dc;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) cnt++;
                }
            }
            remaining[i][j] = cnt; // Initialize undecided cell count
        }
    }

    bt(0); // Start backtracking from the first cell
    if(!solved) printf("no solution\n");

    return 0;
}

/*
Sample input
1 1 2 1 1 1 1 1 0
2 2 3 2 2 3 2 2 0
2 2 3 2 2 3 3 3 1
2 3 2 2 1 2 3 3 2
2 3 1 2 2 3 5 4 3
4 6 3 3 3 4 5 4 3
5 7 4 3 3 4 4 4 3
6 9 6 4 2 2 1 3 3
4 6 4 3 1 1 0 2 2

Sample output
0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 1 0 0
0 1 0 0 1 0 1 0 0
0 0 0 0 0 0 0 1 0
1 0 1 0 0 0 0 1 0
1 0 0 0 1 1 1 1 0
1 1 1 0 0 1 0 0 1
1 1 1 0 0 0 0 0 1
1 1 1 0 1 0 0 0 1
*/