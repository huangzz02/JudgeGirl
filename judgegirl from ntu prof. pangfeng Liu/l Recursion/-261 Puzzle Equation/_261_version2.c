#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void check(char *str1, char *str2, char *str3, int *val) {
    char copy1[20], copy2[20], copy3[20];
    strcpy(copy1, str1);
    strcpy(copy2, str2);
    strcpy(copy3, str3);

    for (int i = 0; copy1[i] != '\0'; i++) {
        if (isupper((unsigned char)copy1[i])) {
            copy1[i] = '0' + val[copy1[i] - 'A'];
        }
    }
    for (int i = 0; copy2[i] != '\0'; i++) {
        if (isupper((unsigned char)copy2[i])) {
            copy2[i] = '0' + val[copy2[i] - 'A'];
        }
    }
    for (int i = 0; copy3[i] != '\0'; i++) {
        if (isupper((unsigned char)copy3[i])) {
            copy3[i] = '0' + val[copy3[i] - 'A'];
        }
    }

    unsigned long long n1 = strtoull(copy1, NULL, 10);
    unsigned long long n2 = strtoull(copy2, NULL, 10);
    unsigned long long n3 = strtoull(copy3, NULL, 10);
    
    if (n1 * n2 == n3) {
        printf("%s x %s = %s\n", copy1, copy2, copy3);
        exit(0);
    }
}

void dfs(int pos, char *unique, int num_unique, int *val, char *str1, char *str2, char *str3) {
    if (pos == num_unique) {
        check(str1, str2, str3, val);
        return;
    }

    for (int d = 0; d <= 9; d++) {
        val[unique[pos] - 'A'] = d;
        dfs(pos + 1, unique, num_unique, val, str1, str2, str3);
    }
}

void solve(char *str1, char *str2, char *str3) {
    char unique[27];
    bool used[26] = {false};
    int num_unique = 0;
    
    for (int i = 0; str1[i] != '\0'; i++) {
        if (isupper((unsigned char)str1[i]) && !used[str1[i] - 'A']) {
            used[str1[i] - 'A'] = true;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (isupper((unsigned char)str2[i]) && !used[str2[i] - 'A']) {
            used[str2[i] - 'A'] = true;
        }
    }
    for (int i = 0; str3[i] != '\0'; i++) {
        if (isupper((unsigned char)str3[i]) && !used[str3[i] - 'A']) {
            used[str3[i] - 'A'] = true;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (used[i]) {
            unique[num_unique++] = 'A' + i;
        }
    }
    /*
        Example: input "ATHF FHTA 5HHTAAF",
                 -> unique = ['A','T','H','F'], num_unique = 4.
    */

    int val[26] = {0};
    
    dfs(0, unique, num_unique, val, str1, str2, str3);
}

int main() {
    char str1[20], str2[20], str3[20];
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    solve(str1, str2, str3);
    return 0;
}

/*
    Change from version1:
    Remove the digit_used[] array to allow repeated digits.

    Note: The question mentions "allowing leading zeros",
          but since repetitive use of letters corresponding to numbers is currently allowed,
          it is not possible to output the example 001 x 002 = 002 normally (version 1 can output it normally).

          example input:
          AAB AAC AAC
          expected output:
          001 x 002 = 002
          actual output:
          000 x 000 = 000
*/