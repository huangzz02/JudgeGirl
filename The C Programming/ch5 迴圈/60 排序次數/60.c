#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        int num[a+1];
        
        for (int j = 0; j < a; j++) {
            scanf(" %d", &num[j]);
        }
        
        int count = 0;
        
        for (int j = 1; j < a; j++) {
            for (int k = 0; k < a - j; k++) {
                if (num[k] > num[k + 1]) {
                    int temp = num[k + 1]; 
                    num[k + 1] = num[k];
                    num[k] = temp;
                        
                    count++;
                }
            }
        }
        
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    
    return 0;
}