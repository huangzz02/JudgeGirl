#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ans[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &ans[i]);
    }

    // sort
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (ans[j] > ans[j + 1]) {
                int temp = ans[j];
                ans[j] = ans[j + 1];
                ans[j + 1] = temp;
            }
        }
    }

    int sum = 0;
    int i = 0;
    while (i < n) {
        int v = ans[i];
        int pick = 0;

        // Calculate how many v was taken
        while (i < n && ans[i] == v) {
            pick++;
            i++;
        }

        if (pick % (v + 1) == 0) { // Case 1
            sum += pick;
        } else { // Case 2
            sum += (pick / (v + 1) + 1) * (v + 1);
        }
        /*
            Case 1:
                Assume the sorted array is [2,2,2,2,2,2,2,2,2,3,4,5],
                pick = 9, v = 2
                Let ans[1], ans[2], ans[3] are same color,
                    ans[4], ans[5], ans[6] are same color,
                    ans[7], ans[8], ans[9] are same color.
                For "2", we have 3 colors, each color have (2 + 1) rabbits.
                So sum += 3 * (2 + 1) = pick = 9.
            
            Case 2:
                Assume the sorted array is [2,2,2,2,2,2,2,2,3,4,5],
                pick = 8, v = 2
                Let ans[1], ans[2], ans[3] are same color,
                    ans[4], ans[5], ans[6] are same color,
                    ans[7], ans[8] are same color.
                For "2", we have 3 colors, first 2 colors have 3 rabbits, 
                         but the last color has only 2 rabbits.
                         (but there's still 1 more rabbit of this color that we don't see)
                So sum += 3 * (2 + 1) = (pick / (v + 1) + 1) * (v + 1) = 11.
                                        -> can be understood as an unconditional carry (because there is a remainder here).
        */
    }

    printf("%d\n", sum);

    return 0;
}
