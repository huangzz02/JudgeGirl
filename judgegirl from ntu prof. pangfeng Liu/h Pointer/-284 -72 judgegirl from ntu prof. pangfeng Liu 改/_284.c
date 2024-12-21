#include <stdio.h>
#include <stdlib.h>

// fill_array.h
void fill_array(int **ptr, int n, int *arr, int m);

// fill_array.c
void fill_array(int **ptr, int n, int *arr, int m) {
    int visited[m];
    for (int i = 0; i < m; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        *ptr[i] = i;
        visited[(ptr[i] - arr)] = 1;
    }

    for (int i = 0; i < m; i++) {
        if (visited[i] == 0) {
            int left = -1, right = -1;

            for (int j = i - 1; j >= 0; j--) {
                if (visited[j] == 1) {
                    left = arr[j];
                    break;
                }
            }

            for (int j = i + 1; j < m; j++) {
                if (visited[j] == 1) {
                    right = arr[j];
                    break;
                }
            }

            if (left != -1 && right != -1) {
                arr[i] = left + right;
            }
        }
    }
}

// main.c
int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int *A = malloc(n * sizeof(int));
    int *arr = malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) {
        arr[i] = -1;
    }
    int **ptr = malloc(m * sizeof(int*));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        ptr[i] = &arr[A[i]];
    }
    fill_array(ptr, n, arr, m);
    for (int i = 0; i < m; i++) {
        printf("%d", arr[i]);
        if(i != m-1) printf(" ");
        else printf("\n");
    }
    free(A);
    free(arr);
    free(ptr);
    return 0;
}