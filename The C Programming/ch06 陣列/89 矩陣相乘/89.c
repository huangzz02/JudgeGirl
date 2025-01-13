#include <stdio.h>

int main(){
    int a1, a2;
    scanf("%d %d", &a1, &a2);
    
    int a_matrix[a1][a2];
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++) {
            scanf("%d", &a_matrix[i][j]);
        }
    }
    
    int b1, b2;
    scanf("%d %d", &b1, &b2);
    
    int b_matrix[b1][b2];
    for (int i = 0; i < b1; i++) {
        for (int j = 0; j < b2; j++) {
            scanf("%d", &b_matrix[i][j]);
        }
    }
    
    int result_matrix[a1][b2];
    
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            result_matrix[i][j] = 0;
        }
    }
    
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            for (int k = 0; k < a2; k++) { //or k < b1 (a2 == b1)
                result_matrix[i][j] += a_matrix[i][k] * b_matrix[k][j];
            }
        }
    }
    
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b2; j++) {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}