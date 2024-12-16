#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int row, col;
    int* data;
} *MATRIX;

int main() {
    MATRIX mat1 = (MATRIX)malloc(sizeof(struct matrix));
    scanf("%d %d", &mat1->row, &mat1->col);
    mat1->data = (int*)malloc(mat1->row * mat1->col * sizeof(int));
    for (int i = 0; i < mat1->row; i++) {
        for (int j = 0; j < mat1->col; j++) {
            scanf("%d", &mat1->data[i * mat1->col + j]);
        }
    }

    MATRIX mat2 = (MATRIX)malloc(sizeof(struct matrix));
    scanf("%d %d", &mat2->row, &mat2->col);
    mat2->data = (int*)malloc(mat2->row * mat2->col * sizeof(int));
    for (int i = 0; i < mat2->row; i++) {
        for (int j = 0; j < mat2->col; j++) {
            scanf("%d", &mat2->data[i * mat2->col + j]);
        }
    }

    if (mat1->row != mat2->row || mat1->col != mat2->col) {
        printf("不可相加\n");
    } else {
        for (int i = 0; i < mat1->row; i++) {
            for (int j = 0; j < mat1->col; j++) {
                if (j == 0) {
                    printf("%d", mat1->data[i * mat1->col + j] + mat2->data[i * mat1->col + j]);
                } else {
                    printf(" %d", mat1->data[i * mat1->col + j] + mat2->data[i * mat1->col + j]);
                }
            }
            printf("\n");
        }
    }

    free(mat1->data);
    free(mat1);
    free(mat2->data);
    free(mat2);

    return 0;
}