#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101];
    int letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            letters[ch - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d\n", letters[i]);
    }

    return 0;
}