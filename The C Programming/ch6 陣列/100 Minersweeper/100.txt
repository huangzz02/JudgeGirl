#include <stdio.h>

int main(){
    int arr[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {0 , -1},          {0 , 1},
                            {1 , -1}, {1 , 0}, {1 , 1} };
                            
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            int count = 0;
            
            if (arr[i][j] == 0) {
                for (int d = 0; d < 8; d++) {
                    int temp_i = i + directions[d][0];
                    int temp_j = j + directions[d][1];
                    
                    if (temp_i >= 0 && temp_i < 4 &&
                        temp_j >= 0 && temp_j < 4   ) {
                        if (arr[temp_i][temp_j] == -1) {
                            count++;
                        }    
                    }
                }
            }
            
            arr[i][j] += count;
            
            printf("%d", arr[i][j]);
            if (j < 3) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}