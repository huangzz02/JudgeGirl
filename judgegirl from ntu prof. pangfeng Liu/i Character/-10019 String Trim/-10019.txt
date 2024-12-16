#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char S[101];
    
    while (fgets(S, sizeof(S), stdin)) {
        int start = 0;
        while (isspace(S[start])) {
            start++;
        }

        int end = strlen(S) - 1;
        while (end >= start && isspace(S[end])) {
            end--;
        }

        S[end + 1] = '\0';

        printf("%s\n", &S[start]);
    }

    return 0;
}