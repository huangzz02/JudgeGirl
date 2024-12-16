#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
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
        int temp_count = 0;
        int ans;
        
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                temp_count++;
                ans = arr[j];
            }
        }
        
        if (temp_count == 1) {
            printf("%d", ans);
            break;
        }
    }
    
    return 0;
}