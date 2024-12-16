#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    int odd_arr[n], count_odd = 0;
    int even_arr[n], count_even = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0) {
            odd_arr[count_odd] = arr[i];
            count_odd++;
        } else {
            even_arr[count_even] = arr[i];
            count_even++;
        }
    }
    
    for (int i = 0; i < count_odd; i++) {
        if (i == 0) {
            printf("%d", odd_arr[i]);
        } else {
            printf(" %d", odd_arr[i]);
        }
    }
    printf("\n");
    
    for (int i = 0; i < count_even; i++) {
        if (i == 0) {
            printf("%d", even_arr[i]);
        } else {
            printf(" %d", even_arr[i]);
        }
    }
    printf("\n");
    
    return 0;
}