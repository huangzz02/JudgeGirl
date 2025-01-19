#include <stdio.h>
#include <string.h>

void print_line(char *line, int length, int m, int spaces_count) {
    int missing_spaces = m - length;
    for (int i = 0; i < length; i++) {
        printf("%c", line[i]);

        if (line[i] == ' ') {
            int insert = 0;
            if ((missing_spaces % spaces_count) != 0) {
                insert = missing_spaces / spaces_count + 1;
            } else {
                insert = missing_spaces / spaces_count;
            }
            missing_spaces -= insert;
            spaces_count--;
            
            for (int j = 0; j < insert; j++) {
                printf(" ");
            }
        }
    }

    if (missing_spaces > 0) { // if "line" only includes one word
        for (int i = 0; i < missing_spaces; i++) {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    int m;
    scanf("%d", &m);

    char temp[m + 1];
    temp[0] = '\0';
    int length = 0, spaces_count = 0;
    
    char input[m + 1];
    while (scanf("%s", input) != EOF) {
        if (length + strlen(input) + (length > 0 ? 1 : 0) <= m) {
            if (length > 0) {
                strcat(temp, " ");
                spaces_count++;
                length++;
            }

            strcat(temp, input);
            length += strlen(input);
        } else {
            print_line(temp, length, m, spaces_count);
            
            strcpy(temp, input);
            length = strlen(input);
            spaces_count = 0;
        }
    }

    if (length > 0) {
        print_line(temp, length, m, spaces_count);
    }

    return 0;
}