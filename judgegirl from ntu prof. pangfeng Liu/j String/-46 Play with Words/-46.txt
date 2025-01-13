#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overflow_check(char **data, int *capacity) {
    if (strlen(*data) + 1 >= *capacity) {
        *capacity *= 2;
        *data = realloc(*data, *capacity * sizeof(char));
    }
}

int main() {
    char input[100];
    int capacity = 100;
    char *data = malloc(capacity * sizeof(char));
    data[0] = '\0'; // started from ""

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 1.insert left x (abcd -> xabcd)
        if (strncmp(input, "insert left", 11) == 0) {
            char x = input[12];
            
            overflow_check(&data, &capacity);

            memmove(data + 1, data, strlen(data) + 1); // remember to move the '\0'
            data[0] = x;
        }

        // 2.insert right x (abcd -> abcdx)
        else if (strncmp(input, "insert right", 12) == 0) {
            char x[2] = {input[13], '\0'};

            overflow_check(&data, &capacity);
            
            strcat(data, x);
        }

        // 3.insert k x (abc, k = 3 -> abxcd)
        else if (strncmp(input, "insert", 6) == 0) {
            int k;
            char x;
            sscanf(input, "insert %d %c", &k, &x);

            overflow_check(&data, &capacity);

            memmove(data + k, data + k - 1, strlen(data) - (k - 1) + 1); // remember to move the '\0'
            data[k - 1] = x;
        }

        // 4.delete left (abcd -> bcd)
        else if (strncmp(input, "delete left", 11) == 0) {
            memmove(data, data + 1, strlen(data));
        }

        // 5.delete right (abcd -> abc)
        else if (strncmp(input, "delete right", 12) == 0) {
            data[strlen(data) - 1] = '\0';
        }

        // 6.delete k (abcd, k = 3 -> abd)
        else if (strncmp(input, "delete", 6) == 0) {
            int k;
            sscanf(input, "delete %d", &k);

            memmove(data + k - 1, data + k, strlen(data) - k + 1); // remember to move the '\0'
        }
    }
    
    int max_count = 1, current_count = 1;
    char max_chars[1001];
    int max_index = 0;

    max_chars[max_index++] = data[0]; // ensure data[0] is involved in max_chars when max = 1

    for (int i = 1; data[i] != '\0'; i++) {
        if (data[i] == data[i - 1]) {
            current_count++;
        } else {
            current_count = 1;
        }

        if (current_count > max_count) {
            max_count = current_count;
            max_index = 0;
            max_chars[max_index++] = data[i];
        } else if (current_count == max_count) {
            max_chars[max_index++] = data[i];
        }
    }
    
    if (strlen(data) != 0) {
        for (int i = 0; i < max_index; i++) {
            printf("%c ", max_chars[i]);
        }
        printf("%d\n", max_count);
    } else {
        printf("0\n"); // the max of empty string is 0
    }

    free(data);
    return 0;
}