#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101];
    int digits = 0, letters = 0, vowels = 0, consonants = 0;

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            digits++;
        } else if (isalpha(str[i])) {
            letters++;
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("%d %d %d %d\n", digits, letters, vowels, consonants);
    
    return 0;
}
