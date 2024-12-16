#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

double distance(int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) > 100 || abs(y1 - y2) > 100) {
        return 100; // overflow (100 > 40 is enough)
    } else {
        return sqrt((double)((x1 - x2) * (x1 - x2) +
                             (y1 - y2) * (y1 - y2)  ));
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int test_case = 0; test_case < n; test_case++) {
        int arr[3][3];
        for (int i = 0; i < 3; i++) {
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        }
        
        //x1, y1, r1
        //x2, y2, r2
        //x3, y3, r3

        double c1c2 = distance(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
        double c2c3 = distance(arr[1][0], arr[1][1], arr[2][0], arr[2][1]);
        double c1c3 = distance(arr[0][0], arr[0][1], arr[2][0], arr[2][1]);

        //printf("c1c2:%f\n", c1c2);
        //printf("c2c3:%f\n", c2c3);
        //printf("c1c3:%f\n", c1c3);

        int is_away[3] = {0, 0, 0}; // {c1, c2, c3}

        if (c1c2 > 40 && c1c3 > 40) {
            is_away[0] = 1;
        }
        if (c1c2 > 40 && c2c3 > 40) {
            is_away[1] = 1;
        }
        if (c1c3 > 40 && c2c3 > 40) {
            is_away[2] = 1;
        }

        //printf("is_away: %d %d %d\n", is_away[0], is_away[1], is_away[2]);

        int x_range_min = INT_MAX;
        int x_range_max = INT_MIN;
        int y_range_min = INT_MAX;
        int y_range_max = INT_MIN;

        int count = 0;

        for (int i = 0; i < 3; i++) {
            // search from "top left corner"
            // from left to right, top to bottom

            int x_temp_min = arr[i][0] - arr[i][2]; // x - r
            int x_temp_max = arr[i][0] + arr[i][2]; // x + r
            int y_temp_min = arr[i][1] - arr[i][2]; // y - r
            int y_temp_max = arr[i][1] + arr[i][2]; // y + r

            if (is_away[i]) {
                int x = arr[i][0];
                int y = arr[i][1];
                int r = arr[i][2];

                int x_temp = x_temp_min;
                int y_temp = y_temp_max;

                while (y_temp >= y_temp_min) {
                    while (x_temp <= x_temp_max) {
                        if (distance(x, y, x_temp, y_temp) <= r) {
                            count++;
                        }
                        x_temp++;
                    }
                    x_temp = x_temp_min;
                    y_temp--;
                }
            } else {
                if (x_temp_min < x_range_min) x_range_min = x_temp_min;
                if (x_temp_max > x_range_max) x_range_max = x_temp_max;
                if (y_temp_min < y_range_min) y_range_min = y_temp_min;
                if (y_temp_max > y_range_max) y_range_max = y_temp_max;
            }
        }
        //printf("count:%d\n", count);
        //printf("x_range_min:%d\n", x_range_min);
        //printf("x_range_max:%d\n", x_range_max);
        //printf("y_range_min:%d\n", y_range_min);
        //printf("y_range_max:%d\n", y_range_max);

        int x_temp = x_range_min;
        int y_temp = y_range_max;

        while (y_temp >= y_range_min) { 
            while (x_temp <= x_range_max) { // find every spot in range
                int check = 0;

                for (int i = 0; i < 3; i++) { // for every spot
                    if (is_away[i]) {
                        continue;
                    } else {
                        int x = arr[i][0];
                        int y = arr[i][1];
                        int r = arr[i][2];
                        if (distance(x, y, x_temp, y_temp) <= r) {
                            check++;
                        }
                    }
                }

                if ((check % 2 != 0) && (check != 0)) {
                    count++;
                    //printf("x:%d, ", x_temp);
                    //printf("y:%d\n", y_temp);
                }

                x_temp++;
            }
            x_temp = x_range_min;
            y_temp--;
        }
        printf("%d\n", count);
    }
    
	return 0;
}