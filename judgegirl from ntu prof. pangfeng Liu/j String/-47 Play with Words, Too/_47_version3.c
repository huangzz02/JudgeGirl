#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overflow_check(char **data, int *capacity, int n, int length) {
    if (length + n >= *capacity) {
        *capacity = length + n + 1;
        *data = realloc(*data, *capacity * sizeof(char));
    }
}

int main() {
    char input[100];
    int capacity = 100;
    char *data = calloc(capacity, sizeof(char)); // started from "\0"
    int length = 0;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 1.insert left x n (abcd, n = 4 -> xxxxabcd)
        if (strncmp(input, "insert left", 11) == 0) {
            char x;
            int n;
            sscanf(input, "insert left %c %d", &x, &n);
            
            overflow_check(&data, &capacity, n, length);

            memmove(data + n, data, length + 1); // remember to move the '\0'

            memset(data, x, n);

            length += n;
        }

        // 2.insert right x n (abcd, n = 4 -> abcdxxxx)
        else if (strncmp(input, "insert right", 12) == 0) {
            char x;
            int n;
            sscanf(input, "insert right %c %d", &x, &n);

            overflow_check(&data, &capacity, n, length);
            
            memset(data + length, x, n);
            data[length + n] = '\0';

            length += n;
        }

        // 3.insert k x n (abc, k = 3, n = 4 -> abxxxxcd)
        else if (strncmp(input, "insert", 6) == 0) {
            int k, n;
            char x;
            sscanf(input, "insert %d %c %d", &k, &x, &n);

            overflow_check(&data, &capacity, n, length);

            memmove(data + k - 1 + n, data + k - 1, length - (k - 1) + 1); // remember to move the '\0'

            memset(data + k - 1, x, n);

            length += n;
        }

        // 4.print
        else if (strcmp(input, "print\n") == 0) {
            for (int i = 0; data[i] != '\0'; i++) {
                int count = 1;
                while (data[i + 1] != '\0' && data[i] == data[i + 1]) {
                    count++;
                    i++;
                }
                printf("%c %d ", data[i], count);
            }
            printf("%c\n", '$');
        }

    }

    free(data);
    return 0;
}
/*
    Score: MLE70

    Compared with the second version:
    1. Changed the logic of the "print".
    2. Use more efficient "memset" instead of for loop.
    3. Use "calloc" instead of "malloc" (line 15).
*/