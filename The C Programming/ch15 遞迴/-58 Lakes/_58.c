#include <stdio.h>
#include <stdlib.h>

int data[400][400];
int visited[400][400];

int dfs(int start, int end, int n, int m) {
    if (start < 0 || start >= n || end < 0 || end >= m || (data[start][end] == 0) || (visited[start][end] == 1)){
        return 0;
    }

    visited[start][end] = 1;

    return 1 + dfs(start + 1, end, n, m)
             + dfs(start - 1, end, n, m)
             + dfs(start, end + 1, n, m)
             + dfs(start, end - 1, n, m);
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

void lake(int n, int m) {
    int *arr = (int *)malloc(((n * m) / 2 + 1) *sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 1 && visited[i][j] == 0) {
                arr[count] = dfs(i, j, n, m);
                count++;
            }
        }
    }
    
    qsort(arr, count, sizeof(int), compare);

    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    lake(n, m);
    return 0;
}