#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        int arr[n];
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        
        int max = arr[0] - arr[1];
        
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                
                int temp = arr[j] - arr[k];
            
                if (temp > max) {
                    max = temp;
                }
            }
        }
        
        printf("%d\n", max);
    }

    return 0;
}