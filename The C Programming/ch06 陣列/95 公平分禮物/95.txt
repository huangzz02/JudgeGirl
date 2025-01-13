#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int sum = 0;
    
    for (int i = 1; i <= max; i++) {
        int temp = 0;
        
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                temp++;
            }
        }
        
        sum += temp / k;
    }
    
    printf("%d\n", sum);
    
    return 0;
}