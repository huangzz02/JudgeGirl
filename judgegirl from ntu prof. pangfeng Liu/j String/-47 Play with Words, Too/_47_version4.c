#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overflow_check(char **data_a, int **data_b, int *capacity, int n, int length) {
    if (length + n >= *capacity) {
        *capacity *= 2;
        *data_a = realloc(*data_a, *capacity * sizeof(char));
        *data_b = realloc(*data_b, *capacity * sizeof(int));
    }
}

int main() {
    char input[100];
    int capacity = 100;
    char *letters_array = calloc(capacity, sizeof(char));
    int *length_array = calloc(capacity, sizeof(int));
    int length = 0;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 1.insert left x n (abcd, n = 4 -> xxxxabcd)
        if (strncmp(input, "insert left", 11) == 0) {
            char x;
            int n;
            sscanf(input, "insert left %c %d", &x, &n);

            if (letters_array[0] == x) { // The same character already exists at the insertion point
                length_array[0] += n;
                continue;
            }

            overflow_check(&letters_array, &length_array, &capacity, 1, length);

            memmove(letters_array + 1, letters_array, length + 1); // char is 1 byte so it can be represented directly
            memmove(length_array + 1, length_array, (length + 1) * sizeof(int));

            letters_array[0] = x;
            length_array[0] = n;

            length++;
        }

        // 2.insert right x n (abcd, n = 4 -> abcdxxxx)
        else if (strncmp(input, "insert right", 12) == 0) {
            char x;
            int n;
            sscanf(input, "insert right %c %d", &x, &n);

            if (letters_array[length - 1] == x) { // The same character already exists at the insertion point
                length_array[length - 1] += n;
                continue;
            }

            overflow_check(&letters_array, &length_array, &capacity, 1, length);

            letters_array[length] = x;
            length_array[length] = n;

            length++;
        }

        // 3.insert k x n (abc, k = 3, n = 4 -> abxxxxcd)
        else if (strncmp(input, "insert", 6) == 0) {
            int k, n;
            char x;
            sscanf(input, "insert %d %c %d", &k, &x, &n);

            overflow_check(&letters_array, &length_array, &capacity, 2, length);

            if (length == 0) { // Exception when length is 0
                memmove(letters_array + 1, letters_array, length + 1); // char is 1 byte so it can be represented directly
                memmove(length_array + 1, length_array, (length + 1) * sizeof(int));

                letters_array[0] = x;
                length_array[0] = n;

                length++;
            }
            
            else {
                int index = 1;
                for (int i = 0; i <= length; i++) {
                    if (index > k) { // Need to divide "letters_array"
                        if (letters_array[i - 1] == x) { // The same character already exists at the insertion point
                            length_array[i - 1] += n;
                            break;
                        }

                        memmove(letters_array + i + 2, letters_array + i, length - i + 1); // char is 1 byte so it can be represented directly
                        memmove(length_array + i + 2, length_array + i, (length - i + 1) * sizeof(int));

                        letters_array[i] = x;
                        letters_array[i + 1] = letters_array[i - 1];

                        length_array[i - 1] = length_array[i - 1] - (index - k);
                        length_array[i] = n;
                        length_array[i + 1] = index - k;

                        // It is recommended to draw pictures and think about this part by yourself

                        length += 2;

                        break;
                    }

                    else if (index == k) { // No need to divide "letters_array"
                        if (i != 0 && letters_array[i - 1] == x) { // The same character already exists at the insertion point
                            length_array[i - 1] += n;
                            break;
                        } else if (letters_array[i] == x) { // The same character already exists at the insertion point
                            length_array[i] += n;
                            break;
                        }

                        memmove(letters_array + i + 1, letters_array + i, length - i + 1); // char is 1 byte so it can be represented directly
                        memmove(length_array + i + 1, length_array + i, (length - i + 1) * sizeof(int));

                        letters_array[i] = x;
                        length_array[i] = n;

                        length++;

                        break;
                    }

                    else {
                        index += length_array[i];
                    }
                }
            }
        }

        // 4.print
        else if (strcmp(input, "print\n") == 0) {
            for (int i = 0; i < length; i++) {
                printf("%c %d ", letters_array[i], length_array[i]);
            }
            printf("%c\n", '$');
        }
    }

    free(letters_array);
    free(length_array);
    return 0;
}
/*
    Score: TLE40 (worse than version3)
    
    Compared with the third version:
    1. All the program logic has been changed
       to prevent the memory from being unable to store too much data.
 
       Ex:
        insert left g 2
        insert right e 1
        insert 3 l 1
        insert 2 o 2
        
        letters_array : \0 -> g \0 -> g e \0 -> g l e \0 -> g o g l e \0
        length_array  : \0 -> 2 \0 -> 2 1 \0 -> 2 1 1 \0 -> 1 2 1 1 1 \0)
 
       However, the "insert k x n" part will cause a timeout error
       when encountering too large test data.
    2. This question should be a flaw in the test question.
*/