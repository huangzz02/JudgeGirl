#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    double y[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    double sum = 0;
    double x[n];
    /*
        x[i] * A[i][i] + "the sum already known" = y[i]
        x[i] = (y[i] - "the sum already known") / A[i][i]
    */
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }

    return 0;
}