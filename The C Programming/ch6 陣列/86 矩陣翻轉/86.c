#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    int original[a][b];
    int result[b][a];
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &original[i][j]);
        }
    }
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            result[j][i] = original[i][j];
        }
    }
        
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}