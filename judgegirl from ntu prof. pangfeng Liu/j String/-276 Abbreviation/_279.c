#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void print(char *abbr, int *index) {
    abbr[*index] = '\0';
    printf("%s\n", abbr);

    *index = 0;
}

int main() {
    char abbr[128];
    abbr[0] = '\0';
    int index = 0;
    char input[128];
    
    while (scanf("%s", input) != EOF) {
        int len = strlen(input);
        bool hasPeriod = (input[len - 1] == '.');

        if (hasPeriod) {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "of" ) == 0 ||
            strcmp(input, "and") == 0 ||
            strcmp(input, "the") == 0 ||
            strcmp(input, "at" ) == 0) {
                if (hasPeriod) {
                    print(abbr, &index);
                }
                continue;
        }
        
        abbr[index++] = toupper(input[0]);
        
        if (hasPeriod) {
            print(abbr, &index);
        }
    }

    return 0;
}