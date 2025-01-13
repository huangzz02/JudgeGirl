#include <stdio.h>
#include <math.h>

int co_factor (int mat[3][3], int a, int b) {
    double cof_mat[2][2];
    int k = 0, l = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            if (i != a && j != b) {
                cof_mat[k][l] = mat[j][i];
                if (l == 0) {
                    l = 1;
                } else {
                    l = 0;
                    k++;
                }
            }
            
        }
    }
    int det_A = cof_mat[0][0] * cof_mat[1][1] -
                cof_mat[1][0] * cof_mat[0][1];
    return det_A;
}

int main(){
    int matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    double det_A =  matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][0] +
                    matrix[0][2] * matrix[1][0] * matrix[2][1] -
                    matrix[0][2] * matrix[1][1] * matrix[2][0] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1] -
                    matrix[0][1] * matrix[1][0] * matrix[2][2];
    
    double rev_det_A = 1 / det_A;
    
    double new_matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new_matrix[i][j] = co_factor(matrix, i, j);
            
            if ((i + j) % 2 != 0) {
                new_matrix[i][j] = -(new_matrix[i][j]);
            }
            double ans = new_matrix[i][j] * rev_det_A;
            if (fabs(ans) < 1e-6) {
                printf("0 ");
            } else {
                printf("%f ", ans);
            }
        }
        printf("\n");
    }
    
    return 0;
}