#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans_max = 0;
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        
        for (int j = 0; j < i; j++) {
            sum += arr[j];
        }
        
        int max = sum;
        
        for (int j = i; j < n; j++) {
            sum = sum - arr[j - i] + arr[j];
            
            if (sum > max) {
                max = sum;
            }
        }
        
        if (max > ans_max) {
            ans_max = max;
        }
    }
        
    printf("%d\n", ans_max);

    return 0;
}