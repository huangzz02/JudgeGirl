#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int parkinglot[n][4];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &parkinglot[i][j]);
        }

        parkinglot[i][3] = parkinglot[i][2];
        // x, y, capacity, original_capacity
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int min_distance = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (parkinglot[j][2] == 0) {
                continue;
            }

            int delta_x = abs(parkinglot[j][0] - x);
            int delta_y = abs(parkinglot[j][1] - y);
            int distance = delta_x + delta_y;

            if (distance < min_distance) {
                min_distance = distance;
            } 
        }

        int choose = -1;

        for (int j = 0; j < n; j++) {
            if (parkinglot[j][2] == 0) {
                continue;
            }

            int delta_x = abs(parkinglot[j][0] - x);
            int delta_y = abs(parkinglot[j][1] - y);
            int distance = delta_x + delta_y;

            if (distance == min_distance) {
                if ( choose == -1 || // first time
                     parkinglot[j][0] <  parkinglot[choose][0] ||   // x < choose_x
                    (parkinglot[j][0] == parkinglot[choose][0] && 
                     parkinglot[j][1] <  parkinglot[choose][1])  ) { // x == choose_x
                                                                  // y <  choose_y
                    choose = j;
                }
            }
        }

        parkinglot[choose][2]--;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", parkinglot[i][3] - parkinglot[i][2]);
    }
}