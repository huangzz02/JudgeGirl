#include <stdio.h>
#include <string.h>
#include <limits.h>

void distance(char str1[], char str2[], int *d) {
    if (str1[0] == '\0') {
        *d = strlen(str2);
        return;
    } else if (str2[0] == '\0') {
        *d = strlen(str1);
        return;
    }

    if (str1[0] == str2[0]) {
        distance(str1 + 1, str2 + 1, d);
    } else {
        int d1, d2;
        distance(str1, str2 + 1, &d1);
        distance(str1 + 1, str2, &d2);
        *d = 1 + (d1 < d2 ? d1 : d2);
    }
}

int main() {
    char strs[101][11];
    int n = 0;
    while (scanf("%s", strs[n]) != EOF) {
        n++;
    }

    int min_distance = INT_MAX;
    int ID1 = -1, ID2 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d;
            distance(strs[i], strs[j], &d);

            int key_new = 1000 * (i + 1) + (j + 1);
            int key_old = 1000 * ID1 + ID2;
            /*
                If there are multiple sets of minimum distance solutions,
                output the pair with the smallest ID in lexicographical order.

                example1 (first ID is different):
                key_new = 1000 * 1 + 3 = 1003 (1, 3)
                key_old = 1000 * 2 + 10 = 2003 (2, 10)
                1003 < 2003 -> (1, 3) < (2, 10) => true

                example2 (first ID is the same):
                key_new = 1000 * 1 + 3 = 1003 (1, 3)
                key_old = 1000 * 1 + 10 = 1010 (1, 10)
                1003 < 1010 -> (1, 3) < (1, 10) => true

                Supplement (Lexicographical order):
                apple < banana
                apple < apply
                (1, 3) < (2, 10)
                (1, 3) < (1, 10)
            */

            if (d < min_distance || (d == min_distance && key_new < key_old)) {
                min_distance = d;
                ID1 = i + 1;
                ID2 = j + 1;
            }
        }
    }

    printf("%d %d %d\n", min_distance, ID1, ID2);
    return 0;
}
