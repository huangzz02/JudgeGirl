#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int arr_ans[n];
    int last_digit = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr_ans[last_digit] = arr[i];
            last_digit++;
        } else {
            count++;
        }
    }
    
    for (int i = 0; i < last_digit; i++) {
        printf("%d", arr_ans[i]);
        if (i != last_digit - 1) {
            printf(" ");
        } else if (count != 0) {
            printf(" ");
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("0");
        if (i != count - 1) {
            printf(" ");
        }
    }
    
    printf("\n"); 

    return 0;
}