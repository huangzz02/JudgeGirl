#include <stdio.h>
#include <stdbool.h>

bool is_Palindrome(int *arr, int n) {
    int L = 0, R = n - 1;
    while (L < R) {
        if (arr[L] != arr[R]) return false;
        L++;
        R--;
    }
    return true;
}

int main() {
    int data[100];
    int n = 0;
    while (scanf("%d", &data[n]) != EOF) {
        n++;
    }

    int ans_L_i, ans_R_i;
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int ii = i + 1; ii < n; ii++) {
            for (int split = i; split < ii; split++) {
                int left[split - i + 1];
                int L_i = 0;
                for (int L = i; L <= split; L++) {
                    left[L_i] = data[L];
                    L_i++;
                }
                int right[ii - split];
                int R_i = 0;
                for (int R = split + 1; R <= ii; R++) {
                    right[R_i] = data[R];
                    R_i++;
                }
                
                int nL = split - i + 1;
                int nR = ii - split;

                if (is_Palindrome(left, nL) && is_Palindrome(right, nR)) {
                    if (ii - i + 1 >= max) {
                        ans_L_i = i;
                        ans_R_i = ii;
                        max = ii - i + 1;
                    }
                }
            }
        }
    }
    for (int i = ans_L_i; i <= ans_R_i; i++) {
        if (i == ans_L_i) printf("%d", data[i]);
        else printf(" %d", data[i]);
    }
    printf("\n");

    return 0;
}