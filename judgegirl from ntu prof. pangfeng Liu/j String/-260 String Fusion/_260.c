#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void overflow_check(char **data, int *capacity, int lenA, int lenB) {
    if (lenA + lenB >= *capacity) {
        *capacity *= 2;
        *data = realloc(*data, *capacity * sizeof(char));
    }
}

int main() {
    char input[128];
    int capacity = 100;
    char *data = malloc(capacity * sizeof(char));
    data[0] = '\0';
    
    while (scanf("%s", input) != EOF) {
        int lenA = strlen(data);
        int lenB = strlen(input);
        int minLen = lenA > lenB ? lenB : lenA;

        int count = 0;
        for (int i = 1; i <= minLen; i++) {
            if (strncmp(data + lenA - i, input, i) == 0) {
                count = i;
            }
        }

        overflow_check(&data, &capacity, lenA, lenB);
        
        strcat(data, input + count);
    }

    printf("%s\n", data);

    free(data);
    return 0;
}