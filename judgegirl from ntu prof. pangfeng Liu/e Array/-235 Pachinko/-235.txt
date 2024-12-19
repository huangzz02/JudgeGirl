#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l; // left
    int r; // right
} condition;

typedef struct {
    int num; // numerator
    int den; // denominator
} fraction;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    condition **data = (condition **)malloc(n * sizeof(condition *));
    for (int i = 0; i < n; i++) {
        data[i] = (condition *)malloc((i + 1) * sizeof(condition)); // i-th has i + 1 pins
    }

    // input
    for (int i = 0; i < n; i++) { // rows
        for (int j = 0; j <= i; j++) { // pins of each rows
            scanf("%d %d", &data[i][j].l, &data[i][j].r);

            int gcdValue = gcd(data[i][j].l, data[i][j].r); // prevent overflow
            data[i][j].l /= gcdValue;
            data[i][j].r /= gcdValue;
        }
    }

    // store the probability
    fraction **prob = (fraction **)malloc((n + 1) * sizeof(fraction *));
    for (int i = 0; i < n + 1; i++) {
        prob[i] = (fraction *)malloc((i + 1) * sizeof(fraction)); // i-th has i + 1 pins, (n+1)-th is the final bucket
    }

    prob[0][0].num = 1;
    prob[0][0].den = 1;

    for (int i = 1; i < n + 1; i++) { // started from 2nd row, (n+1)-th is the final bucket
        for (int j = 0; j <= i; j++) { // pins
            int tmpNum, tmpDen;
            if (j == 0) { // leftmost
                tmpNum = data[i - 1][j].l * prob[i - 1][j].num;
                tmpDen = (data[i - 1][j].l + data[i - 1][j].r) * prob[i - 1][j].den;
            } else if (j == i) { // rightmost
                tmpNum = data[i - 1][j - 1].r * prob[i - 1][j - 1].num;
                tmpDen = (data[i - 1][j - 1].l + data[i - 1][j - 1].r) * prob[i - 1][j - 1].den;
            } else {
                int leftNum = data[i - 1][j - 1].r * prob[i - 1][j - 1].num;
                int leftDen = (data[i - 1][j - 1].l + data[i - 1][j - 1].r) * prob[i - 1][j - 1].den;
                int left_gcd = gcd(leftNum, leftDen); // prevent overflow
                leftNum /= left_gcd;
                leftDen /= left_gcd;

                int rightNum = data[i - 1][j].l * prob[i - 1][j].num;
                int rightDen = (data[i - 1][j].l + data[i - 1][j].r) * prob[i - 1][j].den;
                int right_gcd = gcd(rightNum, rightDen); // prevent overflow
                rightNum /= right_gcd;
                rightDen /= right_gcd;

                tmpNum = leftNum * rightDen + leftDen * rightNum;
                tmpDen = leftDen * rightDen;
            }

            int gcdValue = gcd(tmpNum, tmpDen); // prevent overflow
            tmpNum /= gcdValue;
            tmpDen /= gcdValue;

            prob[i][j].num = tmpNum;
            prob[i][j].den = tmpDen;
        }
    }
    
    for (int i = 0; i < n + 1; i++) {
        printf("%d/%d\n", prob[n][i].num, prob[n][i].den);
    }

    for (int i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
    for (int i = 0; i < n + 1; i++) {
        free(prob[i]);
    }
    free(prob);
    
    return 0;
}