#include <stdio.h>

void max_check(int count, int arr_check[count], int *max) {
    int num_1 = 0;
    int num_0 = 0;
        
    for (int i = 0; i < count; i++) {
        if (arr_check[i]) {
            num_1++;
        } else {
            num_0++;
        }
    }
    
    if (num_1 == num_0) {
        if (count > *max) {
            *max = count;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = 0;
    
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            
            int count = end - start + 1;
            
            if (count % 2 == 0) {
                int arr_check[count];
                
                for (int k = 0; k < count; k++) {
                    arr_check[k] = arr[start + k];
                }
                
                max_check(count, arr_check, &max);
            }
        }
    }
    
    printf("%d\n", max); 

    return 0;
}