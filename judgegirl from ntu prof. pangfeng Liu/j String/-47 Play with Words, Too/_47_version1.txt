#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overflow_check(char **data, int *capacity, int n) {
    if (strlen(*data) + n >= *capacity) {
        while (strlen(*data) + n >= *capacity) {
            *capacity = (*capacity * 3) / 2 + 100;
        }
        *data = realloc(*data, *capacity * sizeof(char));
    }
}

int main() {
    char input[100];
    int capacity = 100;
    char *data = malloc(capacity * sizeof(char));
    data[0] = '\0'; // started from ""

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 1.insert left x n (abcd, n = 4 -> xxxxabcd)
        if (strncmp(input, "insert left", 11) == 0) {
            char x;
            int n;
            sscanf(input, "insert left %c %d", &x, &n);
            
            overflow_check(&data, &capacity, n);

            memmove(data + n, data, strlen(data) + 1); // remember to move the '\0'
            for (int i = 0; i < n; i++) {
                data[i] = x;
            }
        }

        // 2.insert right x n (abcd, n = 4 -> abcdxxxx)
        else if (strncmp(input, "insert right", 12) == 0) {
            char x;
            int n;
            sscanf(input, "insert right %c %d", &x, &n);

            overflow_check(&data, &capacity, n);
            
            int len = strlen(data);
            for (int i = 0; i < n; i++) {
                data[len + i] = x;
            }
            data[len + n] = '\0';
        }

        // 3.insert k x n (abc, k = 3, n = 4 -> abxxxxcd)
        else if (strncmp(input, "insert", 6) == 0) {
            int k, n;
            char x;
            sscanf(input, "insert %d %c %d", &k, &x, &n);

            overflow_check(&data, &capacity, n);

            memmove(data + k - 1 + n, data + k - 1, strlen(data) - (k - 1) + 1); // remember to move the '\0'
            for (int i = 0; i < n; i++) {
                data[k - 1 + i] = x;
            }
        }

        // 4.print
        else if (strcmp(input, "print\n") == 0) {
            int count = 1;
            for (int i = 0; data[i] != '\0'; i++) {
                if (data[i + 1] != '\0' && data[i] == data[i + 1]) {
                    count++;
                } else {
                    printf("%c %d ", data[i], count);
                    count = 1;
                }
            }
            printf("%c\n", '$');
        }
    }

    free(data);
    return 0;
}
// Score: MLE55