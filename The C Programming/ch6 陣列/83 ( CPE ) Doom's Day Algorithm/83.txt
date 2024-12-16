#include <stdio.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    while (test_case--) {
        int m, d;
        scanf("%d %d", &m, &d);

        // 2011/1/1 is Saturday
        // 2011 doesn't have 2/29

        int s = 0;
        for (int i = 1; i < m; i++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                s += 31;
            }else if (i == 2) {
                s += 28;
            }else {
                s += 30;
            }
        }
        s += d;

        switch (s % 7) {
            case 0: 
                printf("Friday\n");
                break;
            case 1: 
                printf("Saturday\n");
                break;
            case 2: 
                printf("Sunday\n");
                break;
            case 3: 
                printf("Monday\n");
                break;
            case 4: 
                printf("Tuesday\n");
                break;
            case 5: 
                printf("Wednesday\n");
                break;
            case 6: 
                printf("Thursday\n");
                break;
        }
    }
    return 0;
}