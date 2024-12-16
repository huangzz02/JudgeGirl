#include <stdio.h>

int leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return leap_year(year) ? 29 : 28;
        default:
            return -1;
    }
}

int main() {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    
    while (1) {
        int days = days_in_month(y, m);
        if (y < 1000 || y > 3000) {
            printf("invalid\n");
            break;
        } else if (d < 0 || d > 6 || days == -1) {
            printf("invalid\n");
            break;
        }
        
        
        int c = y / 100;
        y = y % 100;
        
        if (m == 1 || m == 2) {
            m += 12;
            y--;
        }
        
        
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        
        for (int i = 0; i < d; i++) {
            printf("   ");
        }
        
        int first_week = 7 - d;
        int day_count = 0;
        for (int i = 1; i <= first_week; i++) {
            printf("%3d", i);
            day_count += 1;
        }
        printf("\n");
        day_count += 1;
        
        int next_line = 0;
        while (days > 0) {
            for (int i = day_count; i < day_count + 7; i++) {
                if (i > days) {
                    days = -1;
                    if ((i - 1 - first_week) % 7 == 0) {
                        next_line = -1;
                    }
                    break;
                }
                printf("%3d", i);
            }
            day_count += 7;
            if (next_line != -1) {
                printf("\n");
            }
        }
        
        printf("=====================\n");
        break;
    }
    
    return 0;
}