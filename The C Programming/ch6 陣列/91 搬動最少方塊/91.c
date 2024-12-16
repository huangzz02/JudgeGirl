#include <stdio.h>

int main(){
    int times = 1;
    while (1) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        int sum = 0;
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] -= sum / n;
            if (arr[i] > 0) {
                count += arr[i];
            }
        }
        
        printf("Set #%d\n", times);
        times++;
        
        printf("The minimum number of moves is %d.\n\n", count);
    }    
    
    return 0;
}