#include <stdio.h>
#include <string.h>

typedef struct {
    char food[65];
    int length;
    char ingredients[10][65];
} foods;

int main() {
    int n;
    scanf("%d", &n);

    foods data[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", data[i].food);
        scanf("%d", &data[i].length);
        for (int j = 0; j < data[i].length; j++) {
            scanf("%s", data[i].ingredients[j]);
        }
    }

    int m;
    scanf("%d", &m);

    while(m--) {
        char A[65], B[65];
        scanf("%s %s", A, B);

        foods comparison[2];

        for (int i = 0; i < n; i++) {
            if (strcmp(data[i].food, A) == 0) {
                comparison[0] = data[i];
            }
            if (strcmp(data[i].food, B) == 0) {
                comparison[1] = data[i];
            }
        }

        char temp[10][65];
        int count = 0;
        for (int i = 0; i < comparison[0].length; i++) {
            for (int j = 0; j < comparison[1].length; j++) {
                if (strcmp(comparison[0].ingredients[i], comparison[1].ingredients[j]) == 0) {
                    strcpy(temp[count], comparison[0].ingredients[i]);
                    count++;
                    break;
                }
            }
        }

        if (count == 0) {
            printf("nothing\n");
        } else {
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (strcmp(temp[i], temp[j]) > 0) {
                        char swap[65];
                        strcpy(swap, temp[i]);
                        strcpy(temp[i], temp[j]);
                        strcpy(temp[j], swap);
                    }
                }
            }

            for (int i = 0; i < count; i++) {
                printf("%s", temp[i]);
                if (i < count - 1) printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
/*
    The test data of "comparison" may be the same,
    so line 37 cannot use "else if".
*/